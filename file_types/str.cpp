#include "str.h"

String::String() : PyObject(){
    type = STRING;
}

String::String(const String& o): String(){
    value = o.value;
};
String& String::operator=(const String& o){
	value = o.value;
	return *this;
}
String::String(String&& o): String(){
    value = "";
	std::swap(value, o.value);
}
String& String::operator=(String&& o){
	if(this == &o) {return *this;};

	value = "";
	std::swap(value, o.value);
	return *this;
}
String::String(const std::string& val) : String(){
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
void String::lower() {
    auto s = std::get_if<std::string>(&value);
    for(size_t i = 0; i < s->size(); i++){
        s->at(i) = std::tolower(s->at(i));
    }
}
void String::upper() {
    auto s = std::get_if<std::string>(&value);
    for(size_t i = 0; i < s->size(); i++){
        s->at(i) = std::toupper(s->at(i));
    }
}
void String::title(){
    auto s = std::get_if<std::string>(&value);
	for(size_t i = 0; i < s->size(); i++){
		bool make_upper = (i==0 || i == s->size() - 1 || (s->at(i-1) == ' '));
		if(make_upper){
			s->at(i) = std::toupper(s->at(i));
		}
	}
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