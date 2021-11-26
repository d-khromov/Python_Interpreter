#include "double.h"

Double::Double(const Double& other): PyObject(), value(other.value){};

Double& Double::operator=(const Double& other){
	value = other.value;
	return *this;
}

Double::Double(double val): PyObject(), value(val){};

Double::Double(Double&& o): PyObject(), value(0.){
    std::swap(value, o.value);
}

Double &Double::operator=(Double &&other) {
    if(this == &other){return *this;};
    Double tmp(std::move(other));
    std::swap(value, tmp.value);
    return *this;
}


// Arithmetics
PyObject* Double::operator+(const Double& other) const {
	auto * p = new Double(other.value + value);
    return p;
}
PyObject* Double::operator-(const Double& other) const {
	auto * p = new Double(value - other.value);
    return p;
}
PyObject* Double::operator-() const {
	auto * p = new Double(-value);
    return p;
}
PyObject* Double::operator*(const Double& other) const{
	auto * p = new Double(value * other.value);
    return p;
}
PyObject* Double::operator/(const Double& other) const{
	auto * p = new Double(value / other.value);
    return p;
}

 // Arithmetics with assignment
Double& Double::operator+=(const Double& other){
	value += other.value;
	return *this;
}
Double& Double::operator-=(const Double& other){
	value -= other.value;
	return *this;
}
Double& Double::operator*=(const Double& other){
	value *= other.value;
	return *this;
}
Double& Double::operator/=(const Double& other){
	value /= other.value;
	return *this;
}

// Arithmetics with Int
PyObject* Double::operator+(const Int& other) const {
	auto p = new Double(other.value + value);
    return p;
}
PyObject* Double::operator-(const Int& other) const {
	auto p = new Double(value - other.value);
    return p;
}
PyObject* Double::operator*(const Int& other) const{
	auto p = new Double(value * other.value);
    return p;
}
PyObject* Double::operator/(const Int& other) const{
	auto p = new Double(value / other.value);
    return p;
}
Double& Double::operator+=(const Int& other){
	value += other.value;
	return *this;
}
Double& Double::operator-=(const Int& other){
	value -= other.value;
	return *this;
}
Double& Double::operator*=(const Int& other){
	value *= other.value;
	return *this;
}
Double& Double::operator/=(const Int& other){
	value /= other.value;
	return *this;
}


// Compare
PyObject* Double::operator==(const Double& other) const{
	return new Bool(value == other.value);
}
PyObject* Double::operator<=(const Double& other) const{
	return new Bool(value <= other.value);
}
PyObject* Double::operator<(const Double& other) const{
	return new Bool(value < other.value);
}
PyObject* Double::operator>=(const Double& other) const{
	return new Bool(value >= other.value);
}
PyObject* Double::operator>(const Double& other) const{
	return new Bool(value > other.value);
}
PyObject* Double::operator!=(const Double& other) const{
	return new Bool(value != other.value);
}

// Compare with Int
PyObject* Double::operator==(const Int& other) const{
	return new Bool(value == other.value);
}
PyObject* Double::operator<=(const Int& other) const{
	return new Bool(value <= other.value);
}
PyObject* Double::operator<(const Int& other) const{
	return new Bool(value < other.value);
}
PyObject* Double::operator>=(const Int& other) const{
	return new Bool(value >= other.value);
}
PyObject* Double::operator>(const Int& other) const{
	return new Bool(value > other.value);
}
PyObject* Double::operator!=(const Int& other) const{
	return new Bool(value != other.value);
}
