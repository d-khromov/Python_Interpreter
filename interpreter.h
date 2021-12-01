#ifndef PYTHON_INTERPRETER_INTERPRETER_H
#define PYTHON_INTERPRETER_INTERPRETER_H

#include <vector>
#include <unordered_map>
#include "frame.h"
#include "opcode.h"
#include "file_types/pyfunction.h"
#include "file_types/builtins.h"
#include "file_types/file_types.h"

using frame_ptr = typename std::shared_ptr<Frame>;

class Interpreter{
private:
    std::vector<frame_ptr> frame_stack;
    frame_ptr frame;
public:
    Interpreter():frame(nullptr){};
    void RunCode(PyCodeObject* code, const std::unordered_map<std::string, ptr>& globals={});
    void RunFrame(const frame_ptr&);
    void MakeBuiltins(const frame_ptr&);
    void CallBuiltinFunction(const frame_ptr&, std::string, size_t, bool kwargs=false);
};

void Interpreter::RunCode(PyCodeObject* code, const std::unordered_map<std::string, ptr>& globals) {
    frame = std::make_shared<Frame>(code, globals);
    MakeBuiltins(frame);
    RunFrame(frame);
}

void Interpreter::MakeBuiltins(const frame_ptr &frame) {
    for(auto name:builtin_func_names){
        frame->builtins[name.first] = std::make_shared<PyFunction>(nullptr, name.first);
    }
}

void Interpreter::RunFrame(const frame_ptr& f) {
    frame_stack.push_back(f);
    frame = f;
    frame->running=true;

    while(frame->running){
        uint8_t instr = frame->code->code[frame->cur_instr]; //get instruction number
        size_t arg = frame->code->code[++(frame->cur_instr)]; // get argument

        switch(instr){
            case POP_TOP:{
                frame->Pop();
                break;
            }
            case ROT_TWO:{
                ptr top = frame->Top();
                ptr second = frame->Peek(1);
                frame->Set(top, 1);
                frame->SetTop(second);
                break;
            }
            case ROT_THREE:{
                ptr top = frame->Top();
                ptr second = frame->Peek(1);
                ptr third = frame->Peek(2);
                frame->Set(top, 2);
                frame->Set(third, 1);
                frame->SetTop(second);
                break;
            }
            case DUP_TOP:{
                ptr top = frame->Top();
                frame->Push(top);
                break;
            }
            case DUP_TOP_TWO:{
                ptr top = frame->Top();
                ptr second = frame->Peek(1);
                frame->Push(second);
                frame->Push(top);
                break;
            }
            case ROT_FOUR:{
                ptr top = frame->Top();
                ptr second = frame->Peek(1);
                ptr third = frame->Peek(2);
                ptr fourth = frame->Peek(3);
                frame->Set(top, 3);
                frame->Set(third, 2);
                frame->Set(fourth,1);
                frame->SetTop(second);
                break;
            }
            case NOP:{
                break;
            }
            case UNARY_NEGATIVE:{
                frame->SetTop(TryMinus<PyObject>(frame->Top()));
                break;
            }
            case UNARY_NOT:{
                frame->SetTop(TryNot(frame->Top()));
                break;
            }
            case BINARY_MULTIPLY:{
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TryMultiply<Int, Double>(t1, t2));
                break;
            }
            case BINARY_ADD:{
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TryAdd<Int, Double, String, Bool>(t1, t2));
                break;
            }
            case BINARY_SUBTRACT:{
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TrySubtract<Int, Double, Bool>(t2, t1));
                break;
            }
            case BINARY_TRUE_DIVIDE:{
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TryDivide<Int, Double>(t2, t1));
                break;
            }
            case GET_LEN:{
                //frame->Push(TrySize<String>(frame->Top())); TODO: doesn't work
                break;
            }
            case BINARY_AND:{
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TryAnd(t2, t1));
                break;
            }
            case BINARY_OR:{
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TryOr(t2, t1));
                break;
            }
            case RETURN_VALUE:{
                frame->retval = frame->Pop();
                if(frame->prev_frame != nullptr){
                    frame->prev_frame->Push(frame->retval);
                }
                frame->running = false;
                frame_stack.pop_back();
                break;
            }
            case STORE_NAME:{
                ptr v = frame->Pop();
                std::string name = frame->code->names[arg];
                frame->locals[name] = v;
                break;
            }
            case DELETE_NAME:{
                std::string name = frame->code->names[arg];
                frame->locals.erase(name);
                break;
            }
            case LOAD_CONST:{
                ptr v = frame->code->consts[arg];
                frame->Push(v);
                break;
            }
            case STORE_GLOBAL:{
                ptr v = frame->Pop();
                std::string name = frame->code->names[arg];
                frame->globals[name] = v;
                break;
            }
            case DELETE_GLOBAL:{
                std::string name = frame->code->names[arg];
                frame->globals.erase(name);
                break;
            }
            case LOAD_NAME:{
                std::string name = frame->code->names[arg];
                if(frame->locals.count(name)==1){
                    frame->Push(frame->locals[name]);
                }else if(frame->globals.count(name)==1){
                    frame->Push(frame->globals[name]);
                }else if(frame->builtins.count(name)==1){
                    frame->Push(frame->builtins[name]);
                }
                break;
            }
            case COMPARE_OP:{
                ptr right = frame->Pop();
                ptr left = frame->Top();
                ptr ret=nullptr;
                switch(arg){
                    case 0:{
                        ret= TryIsLess<Int, Double>(right, left);
                        break;
                    }
                    case 1:{
                        ret= TryIsLessOrEqual<Int, Double>(right, left);
                        break;
                    }
                    case 2:{
                        ret= TryIsEqual<Int, Double, String>(right, left);
                        break;
                    }
                    case 3:{
                        ret= TryNotEqual<Int, Double, String>(right, left);
                        break;
                    }
                    case 4:{
                        ret= TryIsGreater<Int, Double>(right, left);
                        break;
                    }
                    case 5:{
                        ret= TryIsGreaterOrEqual<Int, Double>(right, left);
                        break;
                    }
                }
                frame->Push(ret);
                break;
            }
            case LOAD_GLOBAL:{
                std::string name = frame->code->names[arg];
                if(frame->globals.count(name)==1){
                    frame->Push(frame->globals[name]);
                }else if(frame->builtins.count(name)==1){
                    frame->Push(frame->builtins[name]);
                }
                break;
            }
            case LOAD_FAST:{
                std::string name = frame->code->var_names[arg];
                ptr v = frame->locals[name];
                frame->Push(v);
                break;
            }
            case STORE_FAST:{
                ptr v = frame->Pop();
                std::string name = frame->code->var_names[arg];
                frame->locals[name] = v;
                break;
            }
            case DELETE_FAST:{
                std::string name = frame->code->var_names[arg];
                frame->locals.erase(name);
                break;
            }
            case MAKE_FUNCTION:{
                ptr name = frame->Pop();
                ptr code = frame->Pop();
                std::shared_ptr<PyFunction> function = std::make_shared<PyFunction>(
                        dynamic_cast<PyCodeObject*>(code.get()), dynamic_cast<String*>(name.get())->value);
                frame->Push(function);
                break;
            }
            case CALL_FUNCTION:{
                auto function = std::make_shared<PyFunction>(*dynamic_cast<PyFunction*>(frame->Peek(arg).get()));

                if(frame->builtins.count(function->name)==1){
                    CallBuiltinFunction(frame, function->name, arg);
                    break;
                }

                auto var_names = function->code->var_names;

                std::unordered_map<std::string, ptr> locals;
                for(size_t i=0; i<arg; ++i){
                    if(i<function->code->var_names.size()){
                        locals[var_names[arg-1-i]] = frame->Pop();
                    }
                }

                frame_ptr new_frame = std::make_shared<Frame>(function->code, frame->globals, locals, frame.get());
                RunFrame(new_frame);
                if(!frame_stack.empty()){
                    frame = frame_stack.back();
                }else{
                    frame= nullptr;
                }
                break;
            }
        }
        frame->cur_instr++;
    }
}

void Interpreter::CallBuiltinFunction(const frame_ptr &f, std::string name, size_t arg, bool kwargs) {
    std::vector<ptr> args;
    for(size_t i=0; i<arg; ++i){
        args.push_back(f->Pop());
    }
    ptr retval = nullptr;

    size_t f_code = builtin_func_names[name];
    switch(f_code){
        case 0:{
            print(args);
            break;
        }
    }

    frame->Push(retval);
}


#endif //PYTHON_INTERPRETER_INTERPRETER_H
