#include <vector>
#include <cstdint>

#include "pyobject.h"
#include "int.h"

#ifndef LIST_H
#define LIST_H

class List: public PyObject{
public:
	std::vector<PyObject*> value;
	List() = default;
	~List() = default;

	List(List&& o);
	List& operator=(List&& o);
	List(const List& o);
	List& operator=(const List& o);

	void append(const PyObject&);
	void insert(const size_t, const PyObject&);
	void clear();
	List copy() const;
	void extend(const List&);
	size_t index(const PyObject* const) const;
	PyObject* pop(size_t); // _ or * ???
	void remove();
	void reverse();
	void sort();

	List operator+(const List&) const;
	List operator*(const size_t) const;
};

#endif // LIST_H
