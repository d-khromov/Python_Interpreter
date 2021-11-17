#include "string.h"

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

const char& String::operator[](size_t i) const {
	return value[i];
}
char& String::operator[](size_t i){
	return value[i];
}

const size_t String::size() const{
	return value.size();
}
String String::lower() const {
	std::string tmp;
	for(size_t i = 0; i < size(); i++){
		tmp.push_back(std::tolower(value[i]));
	}
	return String(tmp);
}
String String::upper() const {
	std::string tmp;
	for(size_t i = 0; i < size(); i++){
		tmp.push_back(std::toupper(value[i]));
	}
	return String(tmp);
}
String String::title() const{
	std::string tmp;
	for(size_t i = 0; i < size(); i++){
		bool make_upper = (i==0 || i == size() - 1 || (value[i-1] == ' '));
		if(make_upper){
			tmp.push_back(std::toupper(value[i]));
		}else{
			tmp.push_back(value[i]);
		}
	}
	return String(tmp);
}

String String::operator+(const String& o) const{
	return String(value + o.value);
}

String& String::operator+=(const String& o){
	*this = std::move(String(value + o.value));
	return *this;
}

bool String::operator==(const String& o) const{
	return o.value == value;
}

bool String::operator!=(const String& o) const{
	return o.value != value;
}