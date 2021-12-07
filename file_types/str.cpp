#include "str.h"

String::String(const String& o): PyObject(){
    value = o.value;
};
String& String::operator=(const String& o){
	value = o.value;
	return *this;
}
String::String(String&& o): PyObject(){
    value = "";
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
	return std::get<std::string>(value)[std::get<Int::val_type>(i.value)];
}
char& String::operator[](const Int& i){
    return std::get<std::string>(value)[std::get<Int::val_type>(i.value)];
}

const PyObject* String::size() const{
    return new Int(std::get<std::string>(value).size());
}
PyObject* String::lower() const {
    std::string tmp(std::get<std::string>(value));
	for(size_t i = 0; i < tmp.size(); i++){
		tmp[i] = std::tolower(tmp[i]);
	}
    auto * p = new String(tmp);
	return p;
}
PyObject* String::upper() const {
    std::string tmp(std::get<std::string>(value));
    for(size_t i = 0; i < tmp.size(); i++){
        tmp[i] = std::toupper(tmp[i]);
    }
    auto * p = new String(tmp);
    return p;
}
PyObject* String::title() const{
    std::string tmp(std::get<std::string>(value));
	for(size_t i = 0; i < tmp.size(); i++){
		bool make_upper = (i==0 || i == tmp.size() - 1 || (tmp[i-1] == ' '));
		if(make_upper){
			tmp[i] = std::toupper(tmp[i]);
		}else{
            tmp[i] = std::toupper(tmp[i]);
		}
	}
    auto * p = new String(tmp);
	return p;
}

PyObject* String::operator+(const String& o) const{
	return new String(std::get<std::string>(value) + std::get<std::string>(o.value));
}

String& String::operator+=(const String& o){
	*this = std::move(String(std::get<std::string>(value) + std::get<std::string>(o.value)));
	return *this;
}

PyObject* String::operator==(const String& o) const{
	return new Bool(std::get<std::string>(o.value) == std::get<std::string>(value));
}

PyObject* String::operator!=(const String& o) const{
	return new Bool(std::get<std::string>(o.value) != std::get<std::string>(value));
}