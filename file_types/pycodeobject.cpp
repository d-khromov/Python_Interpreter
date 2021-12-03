#include "pycodeobject.h"
#include <string>

std::string home_dir = "../";

template <class ItType >
ptr convert(ItType it){
    if(it->is_number_integer()){
        return std::make_shared<Int>(it->template get<Int::val_type>());
    }else if(it->is_number_float()){
        return std::make_shared<Double>(it->template get<Double::val_type>());
    }else if(it->is_boolean()){
        return std::make_shared<Bool>(it->template get<Bool::val_type>());
    }else if(it->is_string()){
        return std::make_shared<String>(it->template get<String::val_type>());
    }else if(it->is_object()){
        return std::make_shared<PyCodeObject>(*it);
    }
    return std::make_shared<Int>(0);
}

PyCodeObject::PyCodeObject(const char *pathname) {
    std::ifstream py_file(home_dir + pathname);
    json data;
    py_file >> data;

    PyCodeObject tmp(data);
    std::swap(tmp.code, code);
    std::swap(tmp.names, names);
    std::swap(tmp.var_names, var_names);
    std::swap(tmp.consts, consts);
}

PyCodeObject::PyCodeObject(const json& data) {
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
