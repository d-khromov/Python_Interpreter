#include "pyfunction.h"

PyFunction::PyFunction() : PyObject() {
    type = FUNCTION;
    code = nullptr;
    name = "";
}

PyFunction::PyFunction(PyCodeObject* co, std::string n): PyFunction(){
    code = co;
    name = std::move(n);
}

PyFunction::PyFunction(PyFunction &&other):PyFunction() {
    name = other.name;
    code = other.code;
}

PyFunction &PyFunction::operator=(PyFunction &&other) {
    if (this == &other) return *this;

    PyFunction t(std::move(other));
    std::swap(code, t.code);
    std::swap(name, t.name);
    return *this;
}

PyFunction::PyFunction(const PyFunction &other): PyFunction(){
    name = other.name;
    code = other.code;
}

PyFunction &PyFunction::operator=(const PyFunction &other) {
    if (this == &other) return *this;

    PyFunction t(other);
    std::swap(code, t.code);
    std::swap(name, t.name);
    return *this;
}
