#ifndef PYTHON_INTERPRETER_INTERPRETER_H
#define PYTHON_INTERPRETER_INTERPRETER_H

#include <vector>
#include <map>
#include "file_types/pyobject.h"
#include "frame.h"

class PyCodeObject{};


class Interpreter{
private:
    std::vector<Frame> frame_stack;
    Frame* frame;
public:
    Interpreter():frame(nullptr){};
    void RunCode(const PyCodeObject& code, const std::map<const char*, PyObject>& globals={});
    void RunFrame(Frame* frame);
};

void Interpreter::RunCode(const PyCodeObject& code, const std::map<const char*, PyObject>& globals) {
    frame = new Frame(code, globals, frame);
    RunFrame(frame);
}

void Interpreter::RunFrame(Frame *f) {
    frame_stack.push_back(*f);
    frame = f;
    frame->running=true;

    while(frame->running){
        uint8_t instr = frame->code.code[frame->cur_instr]; //get instruction number

        if(instr>=90){ //instructions with arguments
            PyObject arg = frame->code.code[frame->cur_instr+1]; // get argument
        }

        switch(instr){
            case 64: // BINARY_ADD
                PyObject t1 = frame->Top();
                frame->Pop();
                PyObject t2 = frame->Top();
                frame->Pop();
                frame->Push(t1+t2);
                break;
            case 83: //RETURN VALUE
                frame->retval = frame->Top();
                frame->Pop();
                frame->running=false;
                break;
            case 90: // STORE_NAME
                PyObject v = frame->Top();
                frame->Pop();
                frame->locals[arg] = v;
                break;
            case 100: //LOAD_CONST
                frame->Push(arg);
                break;
            case 101: //LOAD_NAME
                if(frame->locals.count(arg)==1){
                    frame->Push(frame->locals[arg]);
                }else if(frame->globals.count(arg)==1){
                    frame->Push(frame->globals[arg]);
                }else if(frame->builtins.count(arg)==1){
                    frame->Push(frame->builtins[arg]);
                }
                break;
        }

    }
}


#endif //PYTHON_INTERPRETER_INTERPRETER_H
