#include <cstdint>
#include <vector>
#include <string>
#include "../parser/json.hpp"
#include <fstream>

#include "pyobject.h"
#include "int.h"
#include "double.h"
#include "str.h"
#include "list.h"
#include "bool.h"

#ifndef PYCODEOBJECT_H
#define PYCODEOBJECT_H

using json = nlohmann::json;


class PyCodeObject : public PyObject{
public:
    using PyObject::type;
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
    std::vector<ptr> consts;
    std::vector<std::string> names;
    std::vector<std::string> var_names;
    PyCodeObject();
    PyCodeObject(const char* pathname);
    PyCodeObject(const json&);
};

template<class IterType, class Type, class ...oTypes>
ptr convert(IterType it);

#endif // PYCODEOBJECT_H