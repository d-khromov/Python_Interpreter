#include "interpreter.h"
#include "frame.h"
#include "file_types/pycodeobject.h"

int main() {
    PyCodeObject code("parser/builtin_functions.py.cjson");

    Interpreter py;
    py.RunCode(&code);

    return 0;
}
