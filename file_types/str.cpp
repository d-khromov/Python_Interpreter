#include "str.h"

String::String(const String& o): value(o.value){};
String& String::operator=(const String& o){
	value = o.value;
	return *this;
}
String::String(String&& o): value(""){
	std::swap(value, o.value);
}
String& String::operator=(String&& o){
	if(this == &o) {return *this;};

	value = "";
	std::swap(value, o.value);
	return *this;
}
String::String(const std::string& val){
	value = val;	
}

const char& String::operator[](const Int& i) const {
	return value[i.value];
}
char& String::operator[](const Int& i){
	return value[i.value];
}

const PyObject* String::size() const{
    return new Int(value.size());
}
PyObject* String::lower() const {
    std::string tmp;
	for(size_t i = 0; i < value.size(); i++){
		tmp.push_back(std::tolower(value[i]));
	}
    auto * p = new String(tmp);
	return p;
}
PyObject* String::upper() const {
	std::string tmp;
	for(size_t i = 0; i < value.size(); i++){
		tmp.push_back(std::toupper(value[i]));
	}
    auto * p = new String(tmp);
	return p;
}
PyObject* String::title() const{
	std::string tmp;
	for(size_t i = 0; i < value.size(); i++){
		bool make_upper = (i==0 || i == value.size() - 1 || (value[i-1] == ' '));
		if(make_upper){
			tmp.push_back(std::toupper(value[i]));
		}else{
			tmp.push_back(value[i]);
		}
	}
    auto * p = new String(tmp);
	return p;
}

PyObject* String::operator+(const String& o) const{
	return new String(value + o.value);
}

String& String::operator+=(const String& o){
	*this = std::move(String(value + o.value));
	return *this;
}

PyObject* String::operator==(const String& o) const{
	return new Bool(o.value == value);
}

PyObject* String::operator!=(const String& o) const{
	return new Bool(o.value != value);
}