#include "builtins.h"
#include <iomanip>

void print(const std::vector<ptr>& objects, std::string sep, std::string end){
    for(auto obj:objects) {
        switch (obj->type) {
            case INT:
                std::cout << std::get<std::int64_t>(obj->value);
                break;
            case STRING:
                std::cout << std::get<std::string>(obj->value);
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
                print(std::get<std::vector<ptr>>(obj->value), ", ", "");
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