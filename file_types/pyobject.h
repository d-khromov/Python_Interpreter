#include <memory>
#include <variant>
#include <vector>
#include <string>
#include <map>

#ifndef PYOBJECT_H
#define PYOBJECT_H
enum BaseTypes {
    INT,
    STRING,
    LIST,
    DOUBLE,
    BOOL,
    CODEOBJECT,
    FUNCTION,
    DICT,
};

class PyObject;
using ptr = typename std::shared_ptr<PyObject>;
using cptr = typename std::shared_ptr<const PyObject>;

using Variable = typename std::variant<
        uint64_t, std::string, double, bool, std::vector<ptr>
>;

class PyObject{
public:
    BaseTypes type;
	PyObject() = default;
	~PyObject() = default;
	PyObject(const PyObject&) = default;
	PyObject(PyObject&&) = default;
    Variable value;

    // Int, Double, ...
    virtual PyObject* operator+(PyObject*) const;
    virtual PyObject* operator-(PyObject*) const;
    virtual PyObject* operator-() const;
    virtual PyObject* operator*(PyObject*) const;
    virtual PyObject* operator/(PyObject*) const;
    virtual PyObject* operator%(PyObject*) const;

    virtual PyObject* operator==(PyObject*) const;
    virtual PyObject* operator!=(PyObject*) const;
    virtual PyObject* operator<=(PyObject*) const;
    virtual PyObject* operator<(PyObject*) const;
    virtual PyObject* operator>=(PyObject*) const;
    virtual PyObject* operator>(PyObject*) const;
    virtual PyObject* operator!() const;

    // Bool
    virtual PyObject* operator&&(PyObject*) const;
    virtual PyObject* operator||(PyObject*) const;

    // String
    virtual const PyObject* size() const;
    virtual PyObject* lower() const;
    virtual PyObject* upper() const;
    virtual PyObject* title() const;

    // List
    virtual void append(PyObject*);
    virtual void insert(PyObject*, PyObject*);
    virtual void clear();
    virtual PyObject* copy() const;
    virtual void extend(PyObject*);
    virtual PyObject* index(PyObject*) const;
    virtual PyObject* pop(PyObject*);
    virtual void remove(PyObject*);
    virtual void reverse();
    virtual void sort();
};


#endif // PYOBJECT_H