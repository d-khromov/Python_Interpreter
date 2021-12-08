#include "pycodeobject.h"

#ifndef PYFUNCTION_H
#define PYFUNCTION_H

class PyFunction: public PyObject{
public:
    using PyObject::type;
    std::shared_ptr<PyCodeObject> code;
    std::string name;

    PyFunction();
    PyFunction(std::shared_ptr<PyCodeObject>, std::string);
    PyFunction(PyFunction&&);
    PyFunction& operator=(PyFunction&&);
    PyFunction(const PyFunction&);
    PyFunction& operator=(const PyFunction&);
    ~PyFunction()=default;
};

#endif // PYFUNCTION_H