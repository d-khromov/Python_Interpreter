#include "int.h"

Int::Int(const Int& other): PyObject(), value(other.value){};
Int& Int::operator=(const Int& other){
	value = other.value;
	return *this;
}
Int::Int(uint64_t val): PyObject(), value(val){};

Int::Int(Int&& o) : PyObject() {
	std::swap(value, o.value);
}
Int& Int::operator=(Int &&other) {
    if(this == &other){return *this;};
    Int tmp(std::move(other));
    std::swap(value, tmp.value);
    return *this;
}

// Arithmetics
PyObject* Int::operator+(const Int& other) const {
    auto * p = new Int(other.value + value);
    return p;
}
PyObject* Int::operator-(const Int& other) const {
    auto * p = new Int(value - other.value);
	return p;
}
PyObject* Int::operator-() const {
	auto *p = new Int(-value);
    return p;
}
PyObject* Int::operator*(const Int& other) const{
	auto *p = new Int(value * other.value);
    return p;
}
PyObject* Int::operator/(const Int& other) const{
	auto *p = new Double(double(value) / double(other.value));
    return p;
}
PyObject* Int::operator%(const Int& other) const{
	auto *p = new Int(value % other.value);
    return p;
}

// Arithmetics with assignment
Int& Int::operator+=(const Int& other){
	value += other.value;
	return *this;
}
Int& Int::operator-=(const Int& other){
	value -= other.value;
	return *this;
}
Int& Int::operator*=(const Int& other){
	value *= other.value;
	return *this;
}
Int& Int::operator/=(const Int& other){
	value /= other.value;
	return *this;
}
Int& Int::operator%=(const Int& other){
	value %= other.value;
	return *this;
}

PyObject* Int::operator+(const Double& other) const {
	auto * p = new Double(other.value + value);
    return p;
}
PyObject* Int::operator-(const Double& other) const {
	auto * p = new Double(value - other.value);
    return p;
}
PyObject* Int::operator*(const Double& other) const{
	auto * p = new Double(value * other.value);
    return p;
}
PyObject* Int::operator/(const Double& other) const{
	auto * p = new Double(double(value) / other.value);
    return p;
}

PyObject* Int::operator==(const Int& other) const{
	return new Bool(value == other.value);
}
PyObject* Int::operator<=(const Int& other) const{
	return new Bool(value <= other.value);
}
PyObject* Int::operator<(const Int& other) const{
	return new Bool(value < other.value);
}
PyObject* Int::operator>=(const Int& other) const{
	return new Bool(value >= other.value);
}
PyObject* Int::operator>(const Int& other) const{
	return new Bool(value > other.value);
}
PyObject* Int::operator!=(const Int& other) const{
	return new Bool(value != other.value);
}

PyObject* Int::operator==(const Double& other) const{
	return new Bool(value == other.value);
}
PyObject* Int::operator<=(const Double& other) const{
	return new Bool(value <= other.value);
}
PyObject* Int::operator<(const Double& other) const{
	return new Bool(value < other.value);
}
PyObject* Int::operator>=(const Double& other) const{
	return new Bool(value >= other.value);
}
PyObject* Int::operator>(const Double& other) const{
	return new Bool(value > other.value);
}
PyObject* Int::operator!=(const Double& other) const{
	return new Bool(value != other.value);
}
