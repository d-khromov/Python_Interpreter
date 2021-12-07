#include "bool.h"

Bool::Bool() : PyObject(){
    type = BOOL;
}

Bool::Bool(Bool && o) : Bool(){
    value = false;
    std::swap(value, o.value);
}

Bool &Bool::operator=(Bool && o) {
    if(this == &o){return *this;}
    std::swap(value, o.value);
    return *this;
}

Bool::Bool(const Bool & o) : Bool(){
    value = o.value;
};

Bool &Bool::operator=(const Bool & o) {
    value = o.value;
    return *this;
}

Bool::Bool(bool val) : Bool(){
    value = val;
}

PyObject *Bool::operator!() const {
    return new Bool(!std::get<bool>(value));
}

PyObject *Bool::operator+(const Bool &h) const {
    return new Bool(std::get<bool>(value) + std::get<bool>(h.value));
}

PyObject* Bool::operator-(const Bool& h) const{
    return new Bool(std::get<bool>(value) - std::get<bool>(h.value));
}

PyObject *Bool::operator&&(const Bool &h) const {
    return new Bool(std::get<bool>(value) && std::get<bool>(h.value));
}

PyObject *Bool::operator||(const Bool &h) const {
    return new Bool(std::get<bool>(value) || std::get<bool>(h.value));
}

Bool::Bool(const Int& o) : Bool(){
    value = bool(std::get<Int::val_type>(o.value));
}

Bool::Bool(const Double &o) : Bool(){
    value = bool(std::get<double>(o.value));
}

PyObject *Bool::operator==(const Bool &h) const {
    return new Bool(std::get<val_type>(value) == std::get<val_type>(h.value));
}

PyObject *Bool::operator!=(const Bool &h) const {
    return new Bool(std::get<val_type>(value) != std::get<val_type>(h.value));
}


