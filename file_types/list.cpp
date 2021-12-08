#include "list.h"

#include <algorithm>

struct Cmp{
    bool operator()(const ptr& a, const ptr& b){
        auto p = TryIsLess<Int, Double>(a, b);
        return std::get<Bool::val_type>(dynamic_cast<Bool*>(p.get())->value);
    }
};

List::List() : PyObject(){
    value = std::vector<ptr>();
    type = LIST;
}

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

void List::append(const ptr& item){
    auto v = TryCopy<Int, Double, String, Bool, List, PyFunction, PyCodeObject, Iterator>(item);
	std::get<val_type>(value).push_back(std::shared_ptr<PyObject>(v));
}
void List::insert(const PyObject* i, PyObject* item){
    auto v = new PyObject(std::move(*item));
	std::get<val_type>(value).insert(
            std::get<val_type>(value).begin() + std::get<Int::val_type>(i->value),
                        ptr(v)
                    );
}
void List::clear(){
    std::get<val_type>(value).clear();
}
PyObject* List::copy() const{
	return new List(*this);
}
void List::extend(const PyObject* o){
	for(size_t i = 0; i < std::get<val_type>(o->value).size(); ++i){
        auto v = new PyObject(std::move(*std::get<val_type>(o->value)[i]));
        std::get<val_type>(value).push_back(ptr(v));
	}
}
PyObject* List::index(const PyObject* obj) const{
	size_t i = 0;
    const auto&  b = std::get<val_type>(value);
	for(; i < b.size(); ++i){
        auto p =TryIsEqual<Int, Double, String, List, Bool>(cptr(obj), b[i]);
		if (std::get<bool>(dynamic_cast<const Bool *>(p.get())->value)){
			break;
		}
	}
	return new Int(i);
}
PyObject* List::pop(const Int& i){
    auto iv = std::get<Int::val_type>(i.value);
	auto tmp = std::get<val_type>(value)[iv];
    std::get<val_type>(value).erase(std::get<val_type>(value).begin() + iv);
	return tmp.get();
}
void List::remove(const PyObject& obj){
	auto * pi = dynamic_cast<Int*>(index(&obj));
    auto i = std::get<Int::val_type>(pi->value);
    std::get<val_type>(value).erase(std::get<val_type>(value).begin() + i);
    delete pi;
}
void List::reverse(){
	std::reverse(std::get<val_type>(value).begin(), std::get<val_type>(value).end());
}
void List::sort(){
    auto * b = &std::get<val_type>(value);
    std::sort<decltype(b->begin()), Cmp>(b->begin(), b->end(), Cmp());
};
PyObject* List::operator+(const List& o) const{
	List tmp(*this);
	tmp.extend(&o);
	return new List(std::move(tmp));
}
PyObject* List::operator*(const Int& i) const{
	List tmp(*this);
	for(size_t j = 0; j < std::get<Int::val_type>(i.value); ++j){
		tmp.extend(&tmp);
	}
	return new List(std::move(tmp));
}

PyObject *List::operator==(const List& o) const {
    return new Bool(o.value == value);
}

PyObject *List::operator!=(const List& o) const {
    return new Bool(o.value != value);;
}

PyObject* List::operator[](const Int& i) const{
    return std::get<val_type>(value)[std::get<Int::val_type>(i.value)].get();
}