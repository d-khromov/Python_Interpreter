#include "pycodeobject.h"
#include <iostream>/////////////////////////////////////////////////////////////////////////////

PyCodeObject::PyCodeObject(const char *pathname) {
    std::ifstream py_file(pathname);
    json data;
    py_file >> data;

    std::cout << typeid(data["names"]).name();
//    names = data["names"];
//    var_names = data["names"];

//    code = data["code"];

    data["consts"];
}