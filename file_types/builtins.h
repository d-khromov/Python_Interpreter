#ifndef BUILTINS_H
#define BUILTINS_H

#include <iostream>
#include <functional>
#include "pyobject.h"


std::unordered_map<std::string, size_t> builtin_func_names = {
        {"print", 0}
};

void print(const std::vector<ptr>& objects, std::string sep=" ", std::string end="\n"){
    for(auto obj:objects){
        if(std::holds_alternative<uint64_t>(obj->value)){
            std::cout<<std::get<std::uint64_t>(obj->value)<<sep;
        }else if(std::holds_alternative<std::string>(obj->value)){
            std::cout<<std::get<std::string>(obj->value)<<sep;
        }else if(std::holds_alternative<double>(obj->value)){
            std::cout<<std::get<double>(obj->value)<<sep;
        }else if(std::holds_alternative<bool>(obj->value)){
            std::cout<<std::get<bool>(obj->value)<<sep;
        }
    }
    std::cout<<end;
}

#endif //BUILTINS_H
