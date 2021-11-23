#include "pyobject.h"
#include <utility>

#ifndef FLOAT_H
#define FLOAT_H

class Int;

class Double: PyObject {
private:
	friend class Int;
public:
	double value;
	Double() = default;
	
	Double(const Double& other);
	Double& operator=(const Double& other);

	Double(Double&& other);
	Double& operator=(Double&& other);
	
	Double(double val);

	~Double() = default;

	// Arithmetics
	Double operator+(const Double& other) const;
	Double operator-(const Double& other) const;
	Double operator-() const;
	Double operator*(const Double& other) const;
	Double operator/(const Double& other) const;
	// Arithmetics with assignment
	Double& operator+=(const Double& other);
	Double& operator-=(const Double& other);
	Double& operator*=(const Double& other);
	Double& operator/=(const Double& other);

	// Arithmetics with Int
	Double operator+(const Int& other) const;
	Double operator-(const Int& other) const;
	Double operator*(const Int& other) const;
	Double operator/(const Int& other) const;
	Double& operator+=(const Int& other);
	Double& operator-=(const Int& other);
	Double& operator*=(const Int& other);
	Double& operator/=(const Int& other);

	// Compare
	bool operator==(const Double& other) const;
	bool operator<=(const Double& other) const;
	bool operator<(const Double& other) const;
	bool operator>=(const Double& other) const;
	bool operator>(const Double& other) const;
	bool operator!=(const Double& other) const;

	// Compare with Int
	bool operator==(const Int& other) const;
	bool operator<=(const Int& other) const;
	bool operator<(const Int& other) const;
	bool operator>=(const Int& other) const;
	bool operator>(const Int& other) const;
	bool operator!=(const Int& other) const;
};

#include "int.h"

#endif // FLOAT_H