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
    using ptr = typename std::shared_ptr<PyObject>;
    uint64_t value;
public:
	Int();

	Int(const Int& other);
	Int& operator=(const Int& other);

	Int(Int&& other);
	Int& operator=(Int&& other);
	
	Int(uint64_t val);

	~Int() = default;

	// Arithmetics
	PyObject* operator+(const Int& other) const;
	PyObject* operator-(const Int& other) const;
	PyObject* operator-() const;
	PyObject* operator*(const Int& other) const;
	PyObject* operator/(const Int& other) const;
	PyObject* operator%(const Int& other) const;
	// Arithmetics with assignment
//	Int& operator+=(const Int& other);
//	Int& operator-=(const Int& other);
//	Int& operator*=(const Int& other);
//	Int& operator/=(const Int& other);
//	Int& operator%=(const Int& other);

	// Arithmetics with Double
	PyObject* operator+(const Double& other) const;
	PyObject* operator-(const Double& other) const;
	PyObject* operator*(const Double& other) const;
	PyObject* operator/(const Double& other) const;
//	Double& operator+=(const Double& other);
//	Double& operator-=(const Double& other);
//	Double& operator*=(const Double& other);
//	Double& operator/=(const Double& other);

	// Compare
//	bool operator==(const Int& other) const;
//	bool operator<=(const Int& other) const;
//	bool operator<(const Int& other) const;
//	bool operator>=(const Int& other) const;
//	bool operator>(const Int& other) const;
//	bool operator!=(const Int& other) const;

	// Compare with Double
//	bool operator==(const Double& other) const;
//	bool operator<=(const Double& other) const;
//	bool operator<(const Double& other) const;
//	bool operator>=(const Double& other) const;
//	bool operator>(const Double& other) const;
//	bool operator!=(const Double& other) const;
};


#endif // INT_H
#include "double.h"
