#include "pyobject.h"
#include <utility>

#ifndef BOOL_H
#define BOOL_H

class Int;
class Double;

class Bool: public PyObject{
    friend class Int;
    friend class Double;
public:
    BaseTypes type = BOOL;
    typedef bool val_type;
    using PyObject::value;
    Bool() = default;
    ~Bool() = default;
    Bool(Bool&&);
    Bool& operator=(Bool&&);
    Bool(const Bool&);
    Bool& operator=(const Bool&);
    Bool(bool val);
    Bool(const Int&);
    Bool(const Double&);

    PyObject* operator!() const;
    PyObject* operator+(const Bool& h) const;
    PyObject* operator-(const Bool& h) const;

    PyObject* operator&&(const Bool& h) const;
    PyObject* operator||(const Bool& h) const;
};

#include "int.h"
#include "double.h"
#endif //BOOL_H
