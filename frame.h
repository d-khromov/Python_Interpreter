#ifndef PYTHON_INTERPRETER_FRAME_H
#define PYTHON_INTERPRETER_FRAME_H
#include "file_types/pyobject.h"

class Frame{
private:
    bool running;
    PyObject* retval;
    PyCodeObject* code;
    Frame* prev_frame;
    std::unordered_map<const char*, PyObject*> globals;
    std::unordered_map<const char*, PyObject*> locals;
    std::unordered_map<const char*, PyObject*> builtins;
    std::vector<PyObject*> value_stack;
    size_t cur_instr;
    friend class Interpreter;
public:
    Frame(PyCodeObject* code, const std::unordered_map<const char*, PyObject*>& globals={}, Frame* prev_frame= nullptr);
    void Push(PyObject*);
    PyObject * Pop();
    void SetTop(PyObject*);
    void Set(PyObject*, size_t n);
    PyObject* Top();
    PyObject* Peek(size_t);
};

Frame::Frame(PyCodeObject* code, const std::unordered_map<const char *, PyObject*> &globals, Frame* prev_frame):
        globals(globals), code(code), prev_frame(prev_frame), locals({}), value_stack({}), cur_instr(0){
    if(prev_frame){
        builtins=prev_frame->builtins;
    }
}

void Frame::Push(PyObject* obj) {
    value_stack.push_back(obj);
}

PyObject* Frame::Pop(){
    PyObject* tmp = value_stack.back();
    value_stack.pop_back();
    return tmp;
}

PyObject* Frame::Top(){
    return value_stack.back();
}

PyObject* Frame::Peek(size_t n){
    return *std::prev(value_stack.end()-n);
}

void Frame::SetTop(PyObject* obj) {
    value_stack.back() = obj;
}

void Frame::Set(PyObject* obj, size_t n) {
    *(value_stack.end()-n-1) = obj;
}


#endif //PYTHON_INTERPRETER_FRAME_H
