#include "list.h"

#include <algorithm>

List::List(List&& o) : List(){
	std::swap(value, o.value);
}
List& List::operator=(List&& o){
	std::swap(value, o.value);
	return *this;
}
List::List(const List& o): List(){
	value = o.value;
}
List& List::operator=(const List& o){
	if(this == &o){ return *this; };

	List tmp(o);
	std::swap(value, tmp.value);
	return *this;
}

void List::append(const PyObject& item){
	value.push_back(&item);
}
void List::insert(const size_t i, const PyObject& item){
	value.insert(i, &item);
}
void List::clear(){
	value.clear();
}
List List::copy() const{
	return List(*this);
}
void List::extend(const List& o){
	for(size_t i = 0; i < o.value.size()){
		value.push_back(o.value[i]);
	}
}
size_t List::index(const PyObject* const obj) const{
	size_t i = 0;
	for(; i < value.size(); ++i){
		if (value[i]->value == obj->value){
			break;
		}
	}
	return i-1;
}
PyObject* List::pop(size_t i){
	auto tmp = value[i];
	value.erase(i);
	return tmp;
}
void List::remove(const PyObject* const obj){
	value.erase(index(obj));
}
void List::reverse(){
	std::reverse(v.begin(), v.end());
}
void List::reverse(){
	std::sort(v.begin(), v.end(), [](const PyObject* const v){return v->value;});
}
List List::operator+(const List& o) const{
	List tmp(*this);
	tmp.extend(o);
	return List(std::move(tmp));
}
List List::operator*(const size_t i) const{
	List tmp(*this);
	for(size_t j = 0; j < i; ++j){
		tmp.extend(tmp);
	}
	return List(std::move(tmp));
}