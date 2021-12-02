#include "pyfunction.h"

PyFunction::PyFunction(PyCodeObject* code, std::string name):code(code), name(std::move(name)){}

PyFunction::PyFunction(PyFunction &&other):name(other.name), code(other.code){}

PyFunction &PyFunction::operator=(PyFunction &&other) {
    if (this == &other) return *this;

    PyFunction t(std::move(other));
    std::swap(code, t.code);
    std::swap(name, t.name);
    return *this;
}

PyFunction::PyFunction(const PyFunction &other):name(other.name), code(other.code) {}

PyFunction &PyFunction::operator=(const PyFunction &other) {
    if (this == &other) return *this;

    PyFunction t(other);
    std::swap(code, t.code);
    std::swap(name, t.name);
    return *this;
}
