#ifndef PYTHON_INTERPRETER_ITERATOR_H
#define PYTHON_INTERPRETER_ITERATOR_H

#include "pyobject.h"
#include "str.h"

class Iterator:public PyObject{
public:
    using PyObject::type;
    std::variant<std::vector<ptr>::iterator, std::string::iterator>it;
    ptr obj;
    bool reached_end;

    ptr next();
    Iterator& iter();
    bool CheckEnd(const ptr&);

    Iterator();
    Iterator(const ptr&);
    Iterator(Iterator&&);
    Iterator& operator=(Iterator&&);
    Iterator(const Iterator&);
    Iterator& operator=(const Iterator&);
    ~Iterator()=default;
};

#endif //PYTHON_INTERPRETER_ITERATOR_H
