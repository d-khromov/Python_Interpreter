#include "pyobject.h"
#include <utility>

#pragma once

class Int;
class Double;

class Bool: public PyObject{
    friend class Int;
    friend class Double;
public:
    typedef bool val_type;
    using PyObject::type;
    using PyObject::value;

    Bool();
    ~Bool() = default;
    Bool(Bool&&);
    Bool& operator=(Bool&&);
    Bool(const Bool&);
    Bool& operator=(const Bool&);
    Bool(bool);
    Bool(const Int&);
    Bool(const Double&);

    PyObject* operator!() const;
    PyObject* operator+(const Bool& h) const;
    PyObject* operator-(const Bool& h) const;
    PyObject* operator==(const Bool& h) const;
    PyObject* operator!=(const Bool& h) const;

    PyObject* operator&&(const Bool& h) const;
    PyObject* operator||(const Bool& h) const;
};

#include "int.h"
#include "double.h"