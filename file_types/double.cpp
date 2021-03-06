#include "double.h"

Double::Double(): PyObject() {
    type = DOUBLE;
}

Double::Double(const Double& other): Double(){
    value = other.value;
};

Double& Double::operator=(const Double& other){
	value = other.value;
	return *this;
}

Double::Double(double val): Double(){
    value = val;
};

Double::Double(Double&& o): Double(){
    value = 0.0;
    std::swap(value, o.value);
}

Double &Double::operator=(Double &&other) {
    if(this == &other){return *this;}
    Double tmp(std::move(other));
    std::swap(value, tmp.value);
    return *this;
}


// Arithmetics
PyObject* Double::operator+(const Double& other) const {
	auto * p = new Double(std::get<double>(other.value) + std::get<double>(value));
    return p;
}
PyObject* Double::operator-(const Double& other) const {
	auto * p = new Double(std::get<double>(value) - std::get<double>(other.value));
    return p;
}
PyObject* Double::operator-() const {
	auto * p = new Double(-std::get<double>(value));
    return p;
}
PyObject* Double::operator*(const Double& other) const{
	auto * p = new Double(std::get<double>(value) * std::get<double>(other.value));
    return p;
}
PyObject* Double::operator/(const Double& other) const{
	auto * p = new Double(std::get<double>(value) / std::get<double>(other.value));
    return p;
}

 // Arithmetics with assignment
Double& Double::operator+=(const Double& other){
	value = std::get<double>(value) + std::get<double>(other.value);
	return *this;
}
Double& Double::operator-=(const Double& other){
    value = std::get<double>(value) - std::get<double>(other.value);
	return *this;
}
Double& Double::operator*=(const Double& other){
	value = std::get<double>(value) * std::get<double>(other.value);
	return *this;
}
Double& Double::operator/=(const Double& other){
    value = std::get<double>(value) / std::get<double>(other.value);
	return *this;
}

// Arithmetics with Int
PyObject* Double::operator+(const Int& other) const {
	auto p = new Double(std::get<double>(other.value) + std::get<double>(value));
    return p;
}
PyObject* Double::operator-(const Int& other) const {
	auto p = new Double(std::get<Int::val_type>(value) - std::get<Int::val_type>(other.value));
    return p;
}
PyObject* Double::operator*(const Int& other) const{
	auto p = new Double(std::get<Int::val_type>(value) * std::get<Int::val_type>(other.value));
    return p;
}
PyObject* Double::operator/(const Int& other) const{
	auto p = new Double(std::get<double>(value) / std::get<Int::val_type>(other.value));
    return p;
}
Double& Double::operator+=(const Int& other){
    value = std::get<double>(value) + std::get<Int::val_type>(other.value);
	return *this;
}
Double& Double::operator-=(const Int& other){
    value = std::get<double>(value) - std::get<Int::val_type>(other.value);
	return *this;
}
Double& Double::operator*=(const Int& other){
    value = std::get<double>(value) * std::get<Int::val_type>(other.value);
	return *this;
}
Double& Double::operator/=(const Int& other){
	value = value = std::get<double>(value) / std::get<Int::val_type>(other.value);
	return *this;
}


// Compare
PyObject* Double::operator==(const Double& other) const{
	return new Bool(std::get<double>(value) == std::get<double>(other.value));
}
PyObject* Double::operator<=(const Double& other) const{
	return new Bool(std::get<double>(value) <= std::get<double>(other.value));
}
PyObject* Double::operator<(const Double& other) const{
	return new Bool(std::get<double>(value) < std::get<double>(other.value));
}
PyObject* Double::operator>=(const Double& other) const{
	return new Bool(std::get<double>(value) >= std::get<double>(other.value));
}
PyObject* Double::operator>(const Double& other) const{
	return new Bool(std::get<double>(value) > std::get<double>(other.value));
}
PyObject* Double::operator!=(const Double& other) const{
	return new Bool(std::get<double>(value) != std::get<double>(other.value));
}

// Compare with Int
PyObject* Double::operator==(const Int& other) const{
	return new Bool(std::get<double>(value) == std::get<Int::val_type>(other.value));
}
PyObject* Double::operator<=(const Int& other) const{
	return new Bool(std::get<double>(value) <= std::get<Int::val_type>(other.value));
}
PyObject* Double::operator<(const Int& other) const{
	return new Bool(std::get<double>(value) < std::get<Int::val_type>(other.value));
}
PyObject* Double::operator>=(const Int& other) const{
	return new Bool(std::get<double>(value) >= std::get<Int::val_type>(other.value));
}
PyObject* Double::operator>(const Int& other) const{
	return new Bool(std::get<double>(value) > std::get<Int::val_type>(other.value));
}
PyObject* Double::operator!=(const Int& other) const{
	return new Bool(std::get<double>(value) != std::get<Int::val_type>(other.value));
}
