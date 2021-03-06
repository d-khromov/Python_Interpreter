#include "pyobject.h"
#include <utility>

#ifndef FLOAT_H
#define FLOAT_H

class Int;

class Double: public PyObject {
private:
	friend class Int;
public:
    using PyObject::value;
    using PyObject::type;
    typedef double val_type;
	Double();
	
	Double(const Double& other);
	Double& operator=(const Double& other);

	Double(Double&& other);
	Double& operator=(Double&& other);
	
	Double(val_type);

	~Double() = default;

	// Arithmetics
	PyObject* operator+(const Double& other) const;
	PyObject* operator-(const Double& other) const;
	PyObject* operator-() const;
	PyObject* operator*(const Double& other) const;
	PyObject* operator/(const Double& other) const;
	// Arithmetics with assignment
	Double& operator+=(const Double& other);
	Double& operator-=(const Double& other);
	Double& operator*=(const Double& other);
	Double& operator/=(const Double& other);

	// Arithmetics with Int
	PyObject* operator+(const Int& other) const;
	PyObject* operator-(const Int& other) const;
	PyObject* operator*(const Int& other) const;
	PyObject* operator/(const Int& other) const;
	Double& operator+=(const Int& other);
	Double& operator-=(const Int& other);
	Double& operator*=(const Int& other);
	Double& operator/=(const Int& other);

	// Compare
	PyObject* operator==(const Double& other) const;
	PyObject* operator<=(const Double& other) const;
	PyObject* operator<(const Double& other) const;
	PyObject* operator>=(const Double& other) const;
	PyObject* operator>(const Double& other) const;
	PyObject* operator!=(const Double& other) const;

	// Compare with Int
	PyObject* operator==(const Int& other) const;
	PyObject* operator<=(const Int& other) const;
	PyObject* operator<(const Int& other) const;
	PyObject* operator>=(const Int& other) const;
	PyObject* operator>(const Int& other) const;
	PyObject* operator!=(const Int& other) const;
};

#endif // FLOAT_H
#include "int.h"
#include "bool.h"
