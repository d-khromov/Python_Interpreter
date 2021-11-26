#include "bool.h"

Bool::Bool(Bool && o) : value(false){
    std::swap(value, o.value);
}

Bool &Bool::operator=(Bool && o) {
    if(this == &o){return *this;}
    std::swap(value, o.value);
    return *this;
}

Bool::Bool(const Bool & o) : value(o.value){};

Bool &Bool::operator=(const Bool & o) {
    value = o.value;
    return *this;
}

Bool::Bool(bool val) {
    value = val;
}

PyObject *Bool::operator!() const {
    return new Bool(!value);
}

PyObject *Bool::operator+(const Bool &h) const {
    return new Bool(value + h.value);
}

PyObject* Bool::operator-(const Bool& h) const{
    return new Bool(value - h.value);
}

PyObject *Bool::operator&&(const Bool &h) const {
    return new Bool(value && h.value);
}

PyObject *Bool::operator||(const Bool &h) const {
    return new Bool(value || h.value);
}

Bool::Bool(const Int& o) {
    value = bool(o.value);
}

Bool::Bool(const Double &o) {
    value = bool(o.value);
}


