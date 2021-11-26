#ifndef PYTHON_INTERPRETER_FRAME_H
#define PYTHON_INTERPRETER_FRAME_H
#include "file_types/file_types.h"
#include "file_types/pycodeobject.h"

class Frame{
private:
    bool running;
    ptr retval;
    PyCodeObject* code;
    Frame* prev_frame;
    std::unordered_map<const char*, ptr> globals;
    std::unordered_map<const char*, ptr> locals;
    std::unordered_map<const char*, ptr> builtins;
    std::vector<ptr> value_stack;
    size_t cur_instr;
    friend class Interpreter;
public:
    Frame(PyCodeObject* code, const std::unordered_map<const char*, ptr>& globals={}, Frame* prev_frame= nullptr);
    void Push(ptr);
    ptr Pop();
    void SetTop(ptr);
    void Set(ptr, size_t n);
    ptr Top();
    ptr Peek(size_t);
};

Frame::Frame(PyCodeObject* code, const std::unordered_map<const char *, ptr> &globals, Frame* prev_frame):
        globals(globals), code(code), prev_frame(prev_frame), locals({}), value_stack({}), cur_instr(0){
    if(prev_frame){
        builtins=prev_frame->builtins;
    }
}

void Frame::Push(ptr obj) {
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

void Frame::SetTop(ptr obj) {
    value_stack.back() = obj;
}

void Frame::Set(ptr obj, size_t n) {
    *(value_stack.end()-n-1) = obj;
}


#endif //PYTHON_INTERPRETER_FRAME_H
