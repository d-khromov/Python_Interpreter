#include "builtins.h"
#include <iomanip>

void print(const std::vector<ptr>& objects, std::string sep, std::string end, bool in_list){
    for(auto obj:objects) {
        switch (obj->type) {
            case INT:
                std::cout << std::get<std::int64_t>(obj->value);
                break;
            case STRING:
                if(in_list) std::cout<<"'";
                std::cout << std::get<std::string>(obj->value);
                if(in_list) std::cout<<"'";
                break;
            case DOUBLE:
                std::cout << std::setprecision(16) << std::get<double>(obj->value);
                if(int(std::get<double>(obj->value)) == std::get<double>(obj->value)){
                    std::cout<<".0";
                }
                break;
            case BOOL:
                std::cout << std::get<bool>(obj->value);
                break;
            case LIST: {
                std::cout << "[";
                print(std::get<std::vector<ptr>>(obj->value), ", ", "", true);
                std::cout << "]";
                break;
            }
        }
        if(obj!=objects.back()){
            std::cout<<sep;
        }
    }
    std::cout<<end;
}

std::shared_ptr<List> range(int64_t start, int64_t stop, int64_t step){
    auto list = std::make_shared<List>(List());
    Int arg;
    if(step>0){
        for(size_t i=start; i<stop; i+=step){
            arg = Int(i);
            list->append(&arg);
        }
    }
    if(step<0){
        for(size_t i=start; i>stop; i+=step){
            arg = Int(i);
            list->append(&arg);
        }
    }
    return list;
}

std::shared_ptr<Int> len(const ptr& obj){
    auto length = std::make_shared<Int>(Int(0));
    switch (obj->type){
        case LIST:
            *length = Int(std::get<std::vector<ptr>>(obj->value).size());
            break;
        case STRING:
            length = std::make_shared<Int>(*dynamic_cast<const Int*>(obj->size()));
            break;
    }
    return length;
}