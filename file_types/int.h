#include <cstdint>
#include <utility>
#include <memory>
#include "pyobject.h"

#ifndef INT_H
#define INT_H

class Double;

class Int: public PyObject {
private:
	friend class Double;
public:
    using PyObject::value;
    using PyObject::type;
    typedef int64_t val_type;
    Int();

	Int(const Int& other);
	Int& operator=(const Int& other);

	Int(Int&& other);
	Int& operator=(Int&& other);
	
	Int(Int::val_type val);

	~Int() = default;

	// Arithmetics
	PyObject* operator+(const Int& other) const;
	PyObject* operator-(const Int& other) const;
	PyObject* operator-() const;
	PyObject* operator*(const Int& other) const;
	PyObject* operator/(const Int& other) const;
	PyObject* operator%(const Int& other) const;
	// Arithmetics with assignment
	Int& operator+=(const Int& other);
	Int& operator-=(const Int& other);
	Int& operator*=(const Int& other);
	Int& operator/=(const Int& other);
	Int& operator%=(const Int& other);

	// Arithmetics with Double
	PyObject* operator+(const Double& other) const;
	PyObject* operator-(const Double& other) const;
	PyObject* operator*(const Double& other) const;
	PyObject* operator/(const Double& other) const;

	// Compare
	PyObject* operator==(const Int& other) const;
	PyObject* operator<=(const Int& other) const;
	PyObject* operator<(const Int& other) const;
	PyObject* operator>=(const Int& other) const;
	PyObject* operator>(const Int& other) const;
	PyObject* operator!=(const Int& other) const;

	// Compare with Double
	PyObject* operator==(const Double& other) const;
	PyObject* operator<=(const Double& other) const;
	PyObject* operator<(const Double& other) const;
	PyObject* operator>=(const Double& other) const;
	PyObject* operator>(const Double& other) const;
	PyObject* operator!=(const Double& other) const;
};

#include "double.h"
#include "bool.h"

#endif // INT_H
