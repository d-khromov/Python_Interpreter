#include <memory>
#include "pyobject.h"
#include "int.h"
#include "double.h"
#include "str.h"
#include "list.h"
#include "bool.h"
#include "pyfunction.h"

using ptr = typename std::shared_ptr<PyObject>;
using cptr = typename std::shared_ptr<const PyObject>;
