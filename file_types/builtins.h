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
        std::cout<<obj<<sep; //TODO: obj -> obj.get_value()
    }
    std::cout<<end;
}

#endif //BUILTINS_H
