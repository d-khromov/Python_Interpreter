#include <memory>
#include "pyobject.h"
#include "int.h"
#include "double.h"
#include "str.h"
#include "list.h"
#include "bool.h"
#include "pyfunction.h"

#ifndef FILE_TYPES_H
#define FILE_TYPES_H

using ptr = typename std::shared_ptr<PyObject>;
using cptr = typename std::shared_ptr<const PyObject>;
/*
template<class Type, class ...oTypes>
ptr TryAdd(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryAdd(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TrySubtract(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TrySubtract(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryMultiply(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryMultiply(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryDivide(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryDivide(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryMinus(const ptr& lhs);

template<class Type, class ...oTypes>
ptr TryMinus(const cptr& lhs);

template<class Type, class ...oTypes>
ptr TrySize(const ptr& lhs);

template<class Type, class ...oTypes>
ptr TrySize(const cptr& lhs);

ptr TryLower(const ptr& lhs);

ptr TryLower(const cptr& lhs);

ptr TryUpper(const ptr& lhs);

ptr TryUpper(const cptr& lhs);

ptr TryTitle(const ptr& lhs);

ptr TryTitle(const cptr& lhs);

template<class Type, class ...oTypes>
ptr TryIsEqual(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsEqual(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryNotEqual(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryNotEqual(const cptr& lhs, const cptr& rhs);

//template<class Type, class ...oTypes>
//ptr TryIsGreater(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsGreater(const cptr& lhs, const cptr& rhs);

//template<class Type, class ...oTypes>
//ptr TryIsLess(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsLess(const cptr& lhs, const cptr& rhs);

//template<class Type, class ...oTypes>
//ptr TryIsGreaterOrEqual(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsGreaterOrEqual(const cptr& lhs, const cptr& rhs);

//template<class Type, class ...oTypes>
//ptr TryIsLessOrEqual(const ptr& lhs, const ptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsLessOrEqual(const cptr& lhs, const cptr& rhs);

//ptr TryNot(const ptr& lhs);

ptr TryNot(const cptr& lhs);

//ptr TryAnd(const ptr& lhs, const ptr& rhs);

ptr TryAnd(const cptr& lhs, const cptr& rhs);

//ptr TryOr(const ptr& lhs, const ptr& rhs);

ptr TryOr(const cptr& lhs, const cptr& rhs);

ptr TryAppend(const ptr& list, const cptr& rhs);

ptr TryInsert(const ptr& list, const ptr& rhs, const cptr& obj);

ptr TryClear(const ptr& list);

ptr TryCopy(const cptr& list);

ptr TryExtend(const ptr& lhs, const ptr& rhs);

std::shared_ptr<PyFunction> make_function(const ptr& code, const ptr& name);
*/
#endif // FILE_TYPES_H