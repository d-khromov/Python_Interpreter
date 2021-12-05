#include <iostream>
#include <functional>
#include "pyobject.h"

#ifndef BUILTINS_H
#define BUILTINS_H

void print(const std::vector<ptr>& objects, std::string sep=" ", std::string end="\n");

#endif // BUILTINS_H