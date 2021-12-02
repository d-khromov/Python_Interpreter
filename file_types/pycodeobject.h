#include <cstdint>
#include <vector>
#include "../parser/json/single_include/nlohmann/json.hpp"
#include <fstream>

#include "pyobject.h"
#include "int.h"
#include "double.h"
#include "str.h"
#include "list.h"
#include "bool.h"

using json = nlohmann::json;

#include "pyobject.h"
#include "int.h"

#ifndef PYCODEOBJECT_H
#define PYCODEOBJECT_H

class PyCodeObject : public PyObject{
public:
//    std::vector<std::shared_ptr<PyObject>> cellvars; // Strings
//    std::vector co_lnotab;
//    std::vector<std::shared_ptr<PyObject>> freevars; // Strings
//    Int argcount;
//    String filename;
//    Int firstlineno;
//    Int flags;
//    Int kwonlyargcount;
//    String name;
//    Int nlocals;
//    Int posonlyargcount;
//    Int stacksize;
    std::vector<uint8_t> code;
    std::vector<std::shared_ptr<PyObject>> consts;
    std::vector<const char*> names;
    std::vector<const char*> var_names;
    PyCodeObject() = default;
    PyCodeObject(const char* pathname);
};
#endif //PYCODEOBJECT_H
