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
        int64_t, std::string, double, bool, std::vector<ptr>
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
    virtual void lower();
    virtual void upper();
    virtual void title();

    // List
    virtual void append(PyObject*);
    virtual void insert(const PyObject*, PyObject*);
    virtual void clear();
    virtual PyObject* copy() const;
    virtual void extend(const PyObject*);
    virtual PyObject* index(PyObject*) const;
    virtual PyObject* pop(PyObject*);
    virtual void remove(PyObject*);
    virtual void reverse();
    virtual void sort();
};


#endif // PYOBJECT_H