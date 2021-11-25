#include <memory>
#include "pyobject.h"
#include "int.h"
#include "double.h"
#include "str.h"
#include "list.h"

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
        return std::shared_ptr<Type>(nullptr);
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
        return std::shared_ptr<Type>(nullptr);
    }else{
        return TryAdd<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryMultiply(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl * *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return std::shared_ptr<Type>(nullptr);
    }else{
        return TryAdd<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryDivide(const ptr& lhs, const ptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    Type * pr = dynamic_cast<Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl / *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return std::shared_ptr<Type>(nullptr);
    }else{
        return TryAdd<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryMinus(const ptr& lhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(-(*pl));
    }else if constexpr (sizeof...(oTypes) == 0) {
        return std::shared_ptr<Type>(nullptr);
    }else{
        return TryAdd<oTypes...>(lhs);
    }
};



#endif // FILE_TYPES_H