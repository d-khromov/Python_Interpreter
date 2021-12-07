#include "pycodeobject.h"
#include <string>
#include <iostream> ///////////////////////////////////////////////////////////

std::string home_dir = "../";

template <class ItType >
ptr convert(ItType it);

template <class ItType >
ptr convert(ItType it){
    if(it->is_number_integer()){
        ptr b = std::make_shared<Int>(it->template get<Int::val_type>());
        return b;
    }else if(it->is_number_float()){
        ptr b = std::make_shared<Double>(it->template get<Double::val_type>());
        return b;
    }else if(it->is_boolean()){
        ptr b = std::make_shared<Bool>(it->template get<Bool::val_type>());
        return b;
    }else if(it->is_array()){
        std::shared_ptr<List> tmp = std::make_shared<List>();
        for(auto i = it->begin(); i != it->end(); ++i){
            auto x = convert<decltype(i)>(i);
            tmp->append(x.get());
        }
        return {nullptr};
    }else if(it->is_string()){
        ptr b = std::make_shared<String>(it->template get<String::val_type>());
        return b;
    }else if(it->is_object()){
        ptr b = std::make_shared<PyCodeObject>(*it);
        return b;
    }
    return std::make_shared<Int>(0);
}

PyCodeObject::PyCodeObject() : PyObject() {
    type = CODEOBJECT;
}

PyCodeObject::PyCodeObject(const char *pathname) : PyCodeObject(){
    std::ifstream py_file(home_dir + pathname);
    json data;
    py_file >> data;

    PyCodeObject tmp(data);
    std::swap(tmp.code, code);
    std::swap(tmp.names, names);
    std::swap(tmp.var_names, var_names);
    std::swap(tmp.consts, consts);
}

PyCodeObject::PyCodeObject(const json& data) : PyCodeObject(){
    for(auto it = data["co_code"].begin(); it != data["co_code"].end(); ++it){
        code.push_back(*it);
    }
    for(auto it = data["co_names"].begin(); it != data["co_names"].end(); ++it){
        names.push_back(*it);
    }
    for(auto it = data["co_varnames"].begin(); it != data["co_varnames"].end(); ++it){
        var_names.push_back(*it);
    }
    for(auto it = data["co_consts"].begin(); it != data["co_consts"].end(); ++it){
        consts.push_back(convert<decltype(it)>(it));
    }
}
