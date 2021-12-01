#include "file_types/pycodeobject.h"

#ifndef PYTHON_INTERPRETER_FRAME_H
#define PYTHON_INTERPRETER_FRAME_H

class Frame{
private:
    bool running;
    ptr retval;
    PyCodeObject* code;
    Frame* prev_frame;
    std::unordered_map<std::string, ptr> globals;
    std::unordered_map<std::string, ptr> locals;
    std::unordered_map<std::string, ptr> builtins;
    std::vector<ptr> value_stack;
    size_t cur_instr;
    friend class Interpreter;
public:
    Frame(PyCodeObject* code,
          std::unordered_map<std::string, ptr>  globals={},
          std::unordered_map<std::string, ptr>  locals={},
          Frame* prev_frame= nullptr);
    void Push(const ptr&);
    ptr Pop();
    void SetTop(const ptr&);
    void Set(const ptr&, size_t n);
    ptr Top();
    ptr Peek(size_t);
};

Frame::Frame(PyCodeObject* code,
             std::unordered_map<std::string, ptr> globals,
             std::unordered_map<std::string, ptr>  locals,
             Frame* prev_frame):
        globals(std::move(globals)), locals(std::move(locals)), code(code), prev_frame(prev_frame), value_stack({}), cur_instr(0), running(false){
    if(prev_frame){
        builtins=prev_frame->builtins;
    }
}

void Frame::Push(const ptr& obj) {
    value_stack.push_back(obj);
}

ptr Frame::Pop(){
    ptr tmp = value_stack.back();
    value_stack.pop_back();
    return tmp;
}

ptr Frame::Top(){
    return value_stack.back();
}

ptr Frame::Peek(size_t n){
    return *std::prev(value_stack.end()-n);
}

void Frame::SetTop(const ptr& obj) {
    value_stack.back() = obj;
}

void Frame::Set(const ptr& obj, size_t n) {
    *std::prev(value_stack.end()-n) = obj;
}


#endif //PYTHON_INTERPRETER_FRAME_H
