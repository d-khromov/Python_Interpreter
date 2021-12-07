#include "file_types/pycodeobject.h"

#ifndef PYTHON_INTERPRETER_FRAME_H
#define PYTHON_INTERPRETER_FRAME_H

class Frame;

using frame_ptr = typename std::shared_ptr<Frame>;

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

#endif // PYTHON_INTERPRETER_FRAME_H