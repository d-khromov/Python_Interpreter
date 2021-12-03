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

void List::append(PyObject* item){
	std::get<val_type>(value).push_back(item);
}
void List::insert(const Int& i, PyObject* item){
	std::get<val_type>(value).insert(std::get<val_type>(value).begin() + std::get<uint64_t>(i.value), item);
}
void List::clear(){
    std::get<val_type>(value).clear();
}
PyObject* List::copy() const{
	return new List(*this);
}
void List::extend(const List& o){
	for(size_t i = 0; i < std::get<val_type>(o.value).size(); ++i){
        std::get<val_type>(value).push_back(std::get<val_type>(o.value)[i]);
	}
}
/*PyObject* List::index(const PyObject* obj) const{
	size_t i = 0;
	for(; i < value.size(); ++i){
		if (value[i] == obj){
			break;
		}
	}
	return new Int(i);
}*/
PyObject* List::pop(const Int& i){
	auto tmp = std::get<val_type>(value)[std::get<uint64_t>(i.value)];
    std::get<val_type>(value).erase(std::get<val_type>(value).begin() + std::get<Int::val_type>(i.value));
	return tmp;
}
/*void List::remove(const PyObject& obj){
	value.erase(index(obj));
}*/
void List::reverse(){
	std::reverse(std::get<val_type>(value).begin(), std::get<val_type>(value).end());
}
/*void List::sort(){
	std::sort(std::get<val_type>(value).begin(), std::get<val_type>(value).end(), [](const PyObject* v){return v->value;});
}*/
PyObject* List::operator+(const List& o) const{
	List tmp(*this);
	tmp.extend(o);
	return new List(std::move(tmp));
}
PyObject* List::operator*(const Int& i) const{
	List tmp(*this);
	for(size_t j = 0; j < std::get<uint64_t>(i.value); ++j){
		tmp.extend(tmp);
	}
	return new List(std::move(tmp));
}