#include <iostream>
#include <functional>
#include "pyobject.h"
#include "../frame.h"

#ifndef BUILTINS_H
#define BUILTINS_H

void print(const std::vector<ptr>& objects, std::string sep=" ", std::string end="\n");

std::shared_ptr<List> range(int64_t start, int64_t stop, int64_t step);

std::shared_ptr<Int> len(const ptr& obj);

#endif // BUILTINS_H