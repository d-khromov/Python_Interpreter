#include "int.h"

Int::Int(const Int& other): value(other.value){};
Int& Int::operator=(const Int& other){
	value = other.value;
	return *this;
}
Int::Int(int val): value(val){};

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
