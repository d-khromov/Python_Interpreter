#include "pyobject.h"
#include <string>
#include <utility>
#include "int.h"

#ifndef STRING_H
#define STRING_H

class String: public PyObject{
public:
    BaseTypes type = STRING;
    typedef std::string val_type;
    using PyObject::value;
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

	PyObject* operator==(const String& o) const;
	PyObject* operator!=(const String& o) const;
};

#endif // STRING_H