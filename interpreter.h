#include <vector>
#include <unordered_map>
#include "frame.h"
#include "opcode.h"
#include "file_types/pyfunction.h"
#include "file_types/builtins.h"
#include "file_types/file_types.h"
#include "file_types/type_funcs.h"

#ifndef INTERPRETER_H
#define INTERPRETER_H

class Interpreter{
private:
    std::vector<frame_ptr> frame_stack;
    frame_ptr frame;
public:
    Interpreter():frame(nullptr){};
    void RunCode(PyCodeObject* code, const std::unordered_map<std::string, ptr>& globals={});
    void RunFrame(const frame_ptr&);
    void MakeBuiltins(const frame_ptr&);
    void CallBuiltinFunction(const frame_ptr&, const std::string&, size_t, bool kwargs=false);
    bool CheckMethod(ptr, const std::string&);
    void CallBuiltinMethod(const frame_ptr&, const std::string&, ptr&, size_t);
};

#endif // INTERPRETER_H