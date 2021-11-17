#ifndef PYTHON_INTERPRETER_FRAME_H
#define PYTHON_INTERPRETER_FRAME_H

class Frame{
private:
    bool running;
    PyObject retval;
    PyCodeObject code;
    Frame* prev_frame;
    std::map<const char*, PyObject> globals;
    std::map<const char*, PyObject> locals;
    std::map<const char*, PyObject> builtins;
    std::vector<PyObject> value_stack;
    size_t cur_instr;
    friend class Interpreter;
public:
    Frame(const PyCodeObject& code, const std::map<const char*, PyObject>& globals, Frame* prev_frame);
    void Push(const PyObject&);
    void Pop();
    PyObject& Top();
};

Frame::Frame(const PyCodeObject &code, const std::map<const char *, PyObject> &globals={}, Frame* prev_frame=nullptr):
        globals(globals), code(code), prev_frame(prev_frame), locals({}), value_stack({}), cur_instr(0){
    if(prev_frame){
        builtins=prev_frame->builtins;
    }
}

void Frame::Push(const PyObject& obj) {
    value_stack.push_back(obj);
}

void Frame::Pop(){
    value_stack.pop_back();
}

PyObject& Frame::Top(){
    return value_stack.back();
}

#endif //PYTHON_INTERPRETER_FRAME_H
