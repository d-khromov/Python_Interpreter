#include <cstdint>
#include "file_types.h"

#ifndef PYCODEOBJECT_H
#define PYCODEOBJECT_H

class PyCodeObject : public PyObject{
public:
    std::vector<uint8_t> code;
    std::vector<ptr> consts;
    std::vector<const char*> names;
    std::vector<const char*> varnames;
    PyCodeObject() = default;
};
#endif //PYCODEOBJECT_H
