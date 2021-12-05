#include "builtins.h"

void print(const std::vector<ptr>& objects, std::string sep, std::string end){
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