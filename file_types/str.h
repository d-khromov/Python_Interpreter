#include "pyobject.h"
#include <string>
#include <utility>

#ifndef STRING_H
#define STRING_H

class String: public PyObject{
public:
	std::string value;
	String() = default;
	~String() = default;
	
	String(const String& o);
	String& operator=(const String& o);
	
	String(String&& o);
	String& operator=(String&& o);

	String(const std::string&);

	const char& operator[](const Int& i) const;
	char& operator[](const Int& i);
	
	const PyObject* size() const;
	PyObject* lower() const;
	PyObject* upper() const;
	PyObject* title() const;

	PyObject* operator+(const String& o) const;
	String& operator+=(const String& o);

	bool operator==(const String& o) const;
	bool operator!=(const String& o) const;
};

#endif // STRING_H