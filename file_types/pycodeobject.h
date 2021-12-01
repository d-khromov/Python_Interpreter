#include <cstdint>
#include <vector>
#include <string>
#include "pyobject.h"

#ifndef PYCODEOBJECT_H
#define PYCODEOBJECT_H

class PyCodeObject : public PyObject{
public:
    std::vector<uint8_t> code;
    std::vector<ptr> consts;
    std::vector<std::string> names;
    std::vector<std::string> var_names;
    PyCodeObject() = default;
};
#endif //PYCODEOBJECT_H
