#include "iterator.h"

Iterator::Iterator(const ptr &obj):obj(obj) {
    switch (obj->type){
        case LIST:{
            it = std::get<std::vector<ptr>>(obj->value).begin();
            break;}
        case STRING:
            it = std::get<std::string>(obj->value).begin();
            break;
    }
    reached_end = CheckEnd(obj);
}

ptr Iterator::next() {

    ptr val;
    switch (obj->type){
        case LIST:{
            val = *std::get<std::vector<ptr>::iterator>(it);
            it = ++std::get<std::vector<ptr>::iterator>(it);
            break;}
        case STRING:
            val = std::make_shared<String>(std::string(1, *std::get<std::string::iterator>(it)));
            it = ++std::get<std::string::iterator>(it);
            break;
    }

    if(CheckEnd(obj)){
        reached_end = true;
    }

    return val;
}

Iterator &Iterator::iter() {
    return *this;
}

bool Iterator::CheckEnd(const ptr &obj) {
    switch (obj->type){
        case LIST:{
            return std::get<std::vector<ptr>::iterator>(it)==std::get<std::vector<ptr>>(obj->value).end();}
        case STRING:
            return std::get<std::string::iterator>(it)==std::get<std::string>(obj->value).end();
    }
    return true;
}

Iterator::Iterator() : PyObject() {
    type = ITERATOR;
    obj = nullptr;
    reached_end = true;
}

Iterator::Iterator(Iterator &&other):Iterator() {
    it = other.it;
    obj = other.obj;
    reached_end = other.reached_end;
}

Iterator &Iterator::operator=(Iterator &&other) {
    if (this == &other) return *this;

    Iterator t(std::move(other));
    std::swap(it, t.it);
    std::swap(obj, t.obj);
    std::swap(reached_end, t.reached_end);
    return *this;
}

Iterator::Iterator(const Iterator &other): Iterator(){
    it = other.it;
    obj = other.obj;
    reached_end = other.reached_end;
}

Iterator &Iterator::operator=(const Iterator &other) {
    if (this == &other) return *this;

    Iterator t(other);
    std::swap(it, t.it);
    std::swap(obj, t.obj);
    std::swap(reached_end, t.reached_end);
    return *this;
}

