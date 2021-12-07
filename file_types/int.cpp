#include "int.h"

Int::Int(const Int& other): PyObject(){
    value =other.value;
};
Int& Int::operator=(const Int& other){
	value = other.value;
	return *this;
}
Int::Int(Int::val_type val): PyObject(){
    value = val;
};

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
    auto * p = new Int(std::get<Int::val_type>(other.value) + std::get<Int::val_type>(value));
    return p;
}
PyObject* Int::operator-(const Int& other) const {
    auto * p = new Int(std::get<Int::val_type>(value) - std::get<Int::val_type>(other.value));
	return p;
}
PyObject* Int::operator-() const {
	auto *p = new Int(-std::get<Int::val_type>(value));
    return p;
}
PyObject* Int::operator*(const Int& other) const{
	auto *p = new Int(std::get<Int::val_type>(value) * std::get<Int::val_type>(other.value));
    return p;
}
PyObject* Int::operator/(const Int& other) const{
	auto *p = new Double(double(std::get<Int::val_type>(value)) / double(std::get<Int::val_type>(other.value)));
    return p;
}
PyObject* Int::operator%(const Int& other) const{
	auto *p = new Int(std::get<Int::val_type>(value) % std::get<Int::val_type>(other.value));
    return p;
}

// Arithmetics with assignment
Int& Int::operator+=(const Int& other){
	value = std::get<Int::val_type>(value) + std::get<Int::val_type>(other.value);
	return *this;
}
Int& Int::operator-=(const Int& other){
	value = std::get<Int::val_type>(value) - std::get<Int::val_type>(other.value);
	return *this;
}
Int& Int::operator*=(const Int& other){
	value = std::get<Int::val_type>(value) * std::get<Int::val_type>(other.value);
	return *this;
}
Int& Int::operator/=(const Int& other){
	value = std::get<Int::val_type>(value) / std::get<Int::val_type>(other.value);
	return *this;
}
Int& Int::operator%=(const Int& other){
	value = std::get<Int::val_type>(value) % std::get<Int::val_type>(other.value);
	return *this;
}

PyObject* Int::operator+(const Double& other) const {
	auto * p = new Double(std::get<double>(other.value) + std::get<Int::val_type>(value));
    return p;
}
PyObject* Int::operator-(const Double& other) const {
	auto * p = new Double(std::get<double>(other.value) - std::get<Int::val_type>(value));
    return p;
}
PyObject* Int::operator*(const Double& other) const{
	auto * p = new Double(std::get<double>(other.value) * std::get<Int::val_type>(value));
    return p;
}
PyObject* Int::operator/(const Double& other) const{
	auto * p = new Double(std::get<double>(other.value) / std::get<Int::val_type>(value));
    return p;
}

PyObject* Int::operator==(const Int& other) const{
	return new Bool(std::get<Int::val_type>(value) == std::get<Int::val_type>(other.value));
}
PyObject* Int::operator<=(const Int& other) const{
	return new Bool(std::get<Int::val_type>(value) <= std::get<Int::val_type>(other.value));
}
PyObject* Int::operator<(const Int& other) const{
	return new Bool(std::get<Int::val_type>(value) < std::get<Int::val_type>(other.value));
}
PyObject* Int::operator>=(const Int& other) const{
	return new Bool(std::get<Int::val_type>(value) >= std::get<Int::val_type>(other.value));
}
PyObject* Int::operator>(const Int& other) const{
	return new Bool(std::get<Int::val_type>(value) > std::get<Int::val_type>(other.value));
}
PyObject* Int::operator!=(const Int& other) const{
	return new Bool(std::get<Int::val_type>(value) != std::get<Int::val_type>(other.value));
}

PyObject* Int::operator==(const Double& other) const{
	return new Bool(std::get<Int::val_type>(value) == std::get<double>(other.value));
}
PyObject* Int::operator<=(const Double& other) const{
	return new Bool(std::get<Int::val_type>(value) <= std::get<double>(other.value));
}
PyObject* Int::operator<(const Double& other) const{
	return new Bool(std::get<Int::val_type>(value) < std::get<double>(other.value));
}
PyObject* Int::operator>=(const Double& other) const{
	return new Bool(std::get<Int::val_type>(value) >= std::get<double>(other.value));
}
PyObject* Int::operator>(const Double& other) const{
	return new Bool(std::get<Int::val_type>(value) > std::get<double>(other.value));
}
PyObject* Int::operator!=(const Double& other) const{
	return new Bool(std::get<Int::val_type>(value) != std::get<double>(other.value));
}
