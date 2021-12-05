#include "bool.h"

Bool::Bool(Bool && o){
    value = false;
    std::swap(value, o.value);
}

Bool &Bool::operator=(Bool && o) {
    if(this == &o){return *this;}
    std::swap(value, o.value);
    return *this;
}

Bool::Bool(const Bool & o){
    value = o.value;
};

Bool &Bool::operator=(const Bool & o) {
    value = o.value;
    return *this;
}

Bool::Bool(bool val) {
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

Bool::Bool(const Int& o) {
    value = bool(std::get<uint64_t>(o.value));
}

Bool::Bool(const Double &o) {
    value = bool(std::get<double>(o.value));
}

PyObject *Bool::operator==(const Bool &h) const {
    return new Bool(std::get<val_type>(value) == std::get<val_type>(h.value));
}

PyObject *Bool::operator!=(const Bool &h) const {
    return new Bool(std::get<val_type>(value) != std::get<val_type>(h.value));
}


