#include "interpreter.h"
#include "frame.h"
#include "file_types/pycodeobject.h"

int main() {
    PyCodeObject code("parser/builtin_methods.py.cjson");

    Interpreter py;
    py.RunCode(std::make_shared<PyCodeObject>(code));

    return 0;
}
