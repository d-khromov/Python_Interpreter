#include <cstdint>
#include <utility>
#include "pyobject.h"

#ifndef INT_H
#define INT_H

class Double;

class Int: public PyObject {
private:
	friend class Double;
public:
	uint64_t value;
	Int() = default;
	
	Int(const Int& other);
	Int& operator=(const Int& other);

	Int(Int&& other);
	Int& operator=(Int&& other);
	
	Int(uint64_t val);

	~Int() = default;

	// Arithmetics
	Int operator+(const Int& other) const;
	Int operator-(const Int& other) const;
	Int operator-() const;
	Int operator*(const Int& other) const;
	Double operator/(const Int& other) const;
	Int operator%(const Int& other) const;
	// Arithmetics with assignment
	Int& operator+=(const Int& other);
	Int& operator-=(const Int& other);
	Int& operator*=(const Int& other);
	Int& operator/=(const Int& other);
	Int& operator%=(const Int& other);

	// Arithmetics with Double
	Double operator+(const Double& other) const;
	Double operator-(const Double& other) const;
	Double operator*(const Double& other) const;
	Double operator/(const Double& other) const;
	Double& operator+=(const Double& other);
	Double& operator-=(const Double& other);
	Double& operator*=(const Double& other);
	Double& operator/=(const Double& other);

	// Compare
	bool operator==(const Int& other) const;
	bool operator<=(const Int& other) const;
	bool operator<(const Int& other) const;
	bool operator>=(const Int& other) const;
	bool operator>(const Int& other) const;
	bool operator!=(const Int& other) const;

	// Compare with Double
	bool operator==(const Double& other) const;
	bool operator<=(const Double& other) const;
	bool operator<(const Double& other) const;
	bool operator>=(const Double& other) const;
	bool operator>(const Double& other) const;
	bool operator!=(const Double& other) const;
};

#include "double.h"

#endif // INT_H