#include <vector>
#include <cstdint>

#include "pyobject.h"
#include "int.h"
#include "type_funcs.h"

#ifndef LIST_H
#define LIST_H

class List: public PyObject{
public:
    using PyObject::value;
    using PyObject::type;
    typedef  std::vector<ptr> val_type;
	List();
	~List() = default;

	List(List&& o);
	List& operator=(List&&);
	List(const List& o);
	List& operator=(const List&);

	void append(PyObject*);
	void insert(const PyObject*, PyObject*) override;
	void clear() override;
	PyObject* copy() const override;
	void extend(const PyObject*) override;
	PyObject* index(const PyObject*) const;
	PyObject* pop(const Int&);
	void remove(const PyObject& obj);
	void reverse() override;
	void sort() override;
    PyObject* operator[](const Int& i) const;

    PyObject* operator+(const List&) const;
    PyObject* operator*(const Int&) const;
    PyObject* operator==(const List&) const;
    PyObject* operator!=(const List&) const;
};

#endif // LIST_H