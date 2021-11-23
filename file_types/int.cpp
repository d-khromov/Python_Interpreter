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
Int Int::operator+(const Int& other) const {
	return Int(other.value + value);
}
Int Int::operator-(const Int& other) const {
	return Int(value - other.value);
}
Int Int::operator-() const {
	return Int(-value);
}
Int Int::operator*(const Int& other) const{
	return Int(value * other.value);
}
Double Int::operator/(const Int& other) const{
	return Double(double(value) / double(other.value));
}
Int Int::operator%(const Int& other) const{
	return Int(value % other.value);
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

Double Int::operator+(const Double& other) const {
	return Double(other.value + value);
}
Double Int::operator-(const Double& other) const {
	return Double(value - other.value);
}
Double Int::operator*(const Double& other) const{
	return Double(value * other.value);
}
Double Int::operator/(const Double& other) const{
	return Double(double(value) / other.value);
}

bool Int::operator==(const Int& other) const{
	return value == other.value;
}
bool Int::operator<=(const Int& other) const{
	return value <= other.value;
}
bool Int::operator<(const Int& other) const{
	return value < other.value;
}
bool Int::operator>=(const Int& other) const{
	return value >= other.value;
}
bool Int::operator>(const Int& other) const{
	return value > other.value;
}
bool Int::operator!=(const Int& other) const{
	return value != other.value;
}

bool Int::operator==(const Double& other) const{
	return value == other.value;
}
bool Int::operator<=(const Double& other) const{
	return value <= other.value;
}
bool Int::operator<(const Double& other) const{
	return value < other.value;
}
bool Int::operator>=(const Double& other) const{
	return value >= other.value;
}
bool Int::operator>(const Double& other) const{
	return value > other.value;
}
bool Int::operator!=(const Double& other) const{
	return value != other.value;
}
