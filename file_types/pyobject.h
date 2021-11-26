#include <memory>

#ifndef PYOBJECT_H
#define PYOBJECT_H

class PyObject{
public:
	PyObject() = default;
	~PyObject() = default;
	PyObject(const PyObject&) = delete;
	PyObject(PyObject&&) = delete;

    // Int, Double
    virtual PyObject* operator+(PyObject* o) const;
    virtual PyObject* operator-(PyObject* o) const;
    virtual PyObject* operator-() const;
    virtual PyObject* operator*(PyObject* o) const;
    virtual PyObject* operator/(PyObject* o) const;
    virtual PyObject* operator%(PyObject* o) const;

    // String
    virtual const PyObject* size() const;
    virtual PyObject* lower() const;
    virtual PyObject* upper() const;
    virtual PyObject* title() const;
};

#endif // PYOBJECT_H