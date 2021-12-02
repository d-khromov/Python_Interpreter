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

template<class Type, class ...oTypes>
ptr TryAdd(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl + *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
            return TryAdd<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TrySubtract(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl - *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TrySubtract<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryMultiply(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl * *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryMultiply<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryDivide(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl / *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryDivide<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryMinus(const ptr& lhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(-(*pl));
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryMinus<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TrySize(const ptr& lhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    if(pl != nullptr){
        auto b = dynamic_cast<const Int*>(pl->size())->value;
        return std::make_shared<Int>(std::get<uint64_t>(b));
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TrySize<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TryLower(const ptr& lhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->lower());
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryLower<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TryUpper(const ptr& lhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->upper());
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryUpper<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TryTitle(const ptr& lhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->title());
    }else if constexpr (sizeof...(oTypes) == 0) {
        return std::shared_ptr<PyObject>(nullptr);
    }else{
        return TryTitle<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TryIsEqual(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl == *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsEqual<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryNotEqual(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl != *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryNotEqual<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsGreater(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl > *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsGreater<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsLess(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl < *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsLess<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsGreaterOrEqual(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl >= *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsGreaterOrEqual<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsLessOrEqual(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl <= *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsLessOrEqual<oTypes...>(lhs, rhs);
    }
}

ptr TryNot(const ptr& lhs){
    Bool * pl = dynamic_cast<Bool*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(!(*pl));
    }
    return {nullptr};
}

ptr TryAnd(const ptr& lhs, const ptr& rhs){
    Bool * pl = dynamic_cast<Bool*>(lhs.get());
    Bool * pr = dynamic_cast<Bool*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl && *pr);
    }
    return {nullptr};
}

ptr TryOr(const ptr& lhs, const ptr& rhs){
    Bool * pl = dynamic_cast<Bool*>(lhs.get());
    Bool * pr = dynamic_cast<Bool*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl || *pr);
    }
    return {nullptr};
}

ptr TryAppend(const ptr& list, const ptr& rhs){
    List * pl = dynamic_cast<List*>(list.get());
    if(pl != nullptr){
        pl->append(rhs.get());
        return list;
    }
    return {nullptr};
}

ptr TryInsert(const ptr& list, const ptr& rhs, const ptr& obj){
    List * pl = dynamic_cast<List*>(list.get());
    Int * pr = dynamic_cast<Int*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        pl->insert(*pr, obj.get());
        return list;
    }
    return {nullptr};
}

ptr TryClear(const ptr& list){
    List * pl = dynamic_cast<List*>(list.get());
    if(pl != nullptr){
        pl->clear();
        return list;
    }
    return {nullptr};
}

ptr TryCopy(const ptr& list){
    List * pl = dynamic_cast<List*>(list.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->copy());
    }
    return {nullptr};
}

ptr TryExtend(const ptr& lhs, const ptr& rhs){
    List * pl = dynamic_cast<List*>(lhs.get());
    List * pr = dynamic_cast<List*>(rhs.get());
    if(pl != nullptr){
        pl->extend(*pr);
        return lhs;
    }
    return {nullptr};
}

std::shared_ptr<PyFunction> make_function(const ptr& code, const ptr& name){

    return std::make_shared<PyFunction>(
            dynamic_cast<PyCodeObject*>(code.get()),
            std::get<std::string>(dynamic_cast<String*>(name.get())->value)
            );
}

#endif // FILE_TYPES_H