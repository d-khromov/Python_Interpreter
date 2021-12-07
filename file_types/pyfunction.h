#include "pycodeobject.h"

#ifndef PYFUNCTION_H
#define PYFUNCTION_H

class PyFunction: public PyObject{
public:
    using PyObject::type;
    PyCodeObject* code;
    std::string name;

    PyFunction();
    PyFunction(PyCodeObject*, std::string);
    PyFunction(PyFunction&&);
    PyFunction& operator=(PyFunction&&);
    PyFunction(const PyFunction&);
    PyFunction& operator=(const PyFunction&);
    ~PyFunction()=default;
};

#endif // PYFUNCTION_H