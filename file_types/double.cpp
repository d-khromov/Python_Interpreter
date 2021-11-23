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
Double Double::operator+(const Double& other) const {
	return Double(other.value + value);
}
Double Double::operator-(const Double& other) const {
	return Double(value - other.value);
}
Double Double::operator-() const {
	return Double(-value);
}
Double Double::operator*(const Double& other) const{
	return Double(value * other.value);
}
Double Double::operator/(const Double& other) const{
	return Double(value / other.value);
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
Double Double::operator+(const Int& other) const {
	return Double(other.value + value);
}
Double Double::operator-(const Int& other) const {
	return Double(value - other.value);
}
Double Double::operator*(const Int& other) const{
	return Double(value * other.value);
}
Double Double::operator/(const Int& other) const{
	return Double(value / other.value);
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
bool Double::operator==(const Double& other) const{
	return value == other.value;
}
bool Double::operator<=(const Double& other) const{
	return value <= other.value;
}
bool Double::operator<(const Double& other) const{
	return value < other.value;
}
bool Double::operator>=(const Double& other) const{
	return value >= other.value;
}
bool Double::operator>(const Double& other) const{
	return value > other.value;
}
bool Double::operator!=(const Double& other) const{
	return value != other.value;
}

// Compare with Int
bool Double::operator==(const Int& other) const{
	return value == other.value;
}
bool Double::operator<=(const Int& other) const{
	return value <= other.value;
}
bool Double::operator<(const Int& other) const{
	return value < other.value;
}
bool Double::operator>=(const Int& other) const{
	return value >= other.value;
}
bool Double::operator>(const Int& other) const{
	return value > other.value;
}
bool Double::operator!=(const Int& other) const{
	return value != other.value;
}
