#include <memory>

#ifndef PYOBJECT_H
#define PYOBJECT_H

class PyObject{
public:
	PyObject() = default;
	~PyObject() = default;
	PyObject(const PyObject&) = delete;
	PyObject(PyObject&&) = delete;

    virtual PyObject* operator+(PyObject* o) const;
    virtual PyObject* operator-(PyObject* o) const;
    virtual PyObject* operator-() const;
    virtual PyObject* operator*(PyObject* o) const;
    virtual PyObject* operator/(PyObject* o) const;
    virtual PyObject* operator%(PyObject* o) const;
};

#endif // PYOBJECT_H