#ifndef PYOBJECT_H
#define PYOBJECT_H

class PyObject{
public:
	PyObject() = default;
	~PyObject() = default;
	PyObject(const PyObject&) = delete;
	PyObject(PyObject&&) = delete;
};

#endif // PYOBJECT_H