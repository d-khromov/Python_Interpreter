#include <vector>
#include <cstdint>

#include "pyobject.h"
#include "int.h"

#ifndef LIST_H
#define LIST_H

class List: public PyObject{
public:
    using PyObject::value;
    BaseTypes type = LIST;
    typedef  std::vector<PyObject*> val_type;
	List() = default;
	~List() = default;

	List(List&& o);
	List& operator=(List&&);
	List(const List& o);
	List& operator=(const List&);

	void append(PyObject*);
	void insert(const Int&, PyObject*);
	void clear() override;
	PyObject* copy() const override;
	void extend(const List&);
    //TODO:
//	PyObject* index(const PyObject*) const;
	PyObject* pop(const Int&);
//	void remove(const PyObject& obj);
	void reverse() override;
//	void sort() override;
// TODO: operator[]

	PyObject* operator+(const List&) const;
	PyObject* operator*(const Int&) const;
};

#endif // LIST_H
