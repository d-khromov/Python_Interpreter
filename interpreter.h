#ifndef PYTHON_INTERPRETER_INTERPRETER_H
#define PYTHON_INTERPRETER_INTERPRETER_H

#include <vector>
#include <unordered_map>
#include "file_types/file_types.h"
#include "file_types/pycodeobject.h"
#include "frame.h"
#include "opcode.h"

class Interpreter{
private:
    std::vector<Frame*> frame_stack;
    Frame* frame;
public:
    Interpreter():frame(nullptr){};
    void RunCode(PyCodeObject* code, const std::unordered_map<const char*, ptr>& globals={});
    void RunFrame(Frame* frame);
};

void Interpreter::RunCode(PyCodeObject* code, const std::unordered_map<const char*, ptr>& globals) {
    frame = new Frame(code, globals, frame);
    RunFrame(frame);
}

void Interpreter::RunFrame(Frame *f) {
    frame_stack.push_back(f);
    frame = f;
    frame->running=true;

    while(frame->running){
        uint8_t instr = frame->code->code[frame->cur_instr]; //get instruction number
        uint8_t arg = frame->code->code[++(frame->cur_instr)]; // get argument

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
            case 64:{// BINARY_ADD
                ptr t1 = frame->Pop();
                ptr t2 = frame->Top();
                frame->SetTop(TryAdd<Int, Int>(t1, t2));
                break;
            }
            case RETURN_VALUE:{
                frame->retval = frame->Pop();
                frame->running = false;
                break;
            }
            case STORE_NAME:{
                ptr v = frame->Pop();
                const char* name = frame->code->names[arg];
                frame->locals[name] = v;
                break;
            }
            case DELETE_NAME:{
                const char* name = frame->code->names[arg];
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
                const char* name = frame->code->names[arg];
                frame->globals[name] = v;
                break;
            }
            case DELETE_GLOBAL:{
                const char* name = frame->code->names[arg];
                frame->globals.erase(name);
                break;
            }
            case LOAD_NAME:{
                const char* name = frame->code->names[arg];
                if(frame->locals.count(name)==1){
                    frame->Push(frame->locals[name]);
                }else if(frame->globals.count(name)==1){
                    frame->Push(frame->globals[name]);
                }else if(frame->builtins.count(name)==1){
                    frame->Push(frame->builtins[name]);
                }
                break;
            }
            case LOAD_GLOBAL:{
                const char* name = frame->code->names[arg];
                if(frame->globals.count(name)==1){
                    frame->Push(frame->globals[name]);
                }else if(frame->builtins.count(name)==1){
                    frame->Push(frame->builtins[name]);
                }
                break;
            }
        }
        frame->cur_instr++;
    }
}


#endif //PYTHON_INTERPRETER_INTERPRETER_H
