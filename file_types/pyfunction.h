#ifndef PYFUNCTION_H
#define PYFUNCTION_H

#include "pycodeobject.h"

class PyFunction:public PyObject{
public:
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

#endif //PYFUNCTION_H
