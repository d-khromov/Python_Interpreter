#include "pycodeobject.h"

#ifndef PYFUNCTION_H
#define PYFUNCTION_H

class PyFunction:public PyObject{
public:
    BaseTypes type = FUNCTION;
    PyCodeObject* code;
    std::string name;

    PyFunction()=default;
    PyFunction(PyCodeObject*, std::string);
    PyFunction(PyFunction&&);
    PyFunction& operator=(PyFunction&&);
    PyFunction(const PyFunction&);
    PyFunction& operator=(const PyFunction&);
    ~PyFunction()=default;
};

#endif // PYFUNCTION_H