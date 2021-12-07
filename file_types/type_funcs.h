#include <memory>

#ifndef FILE_FUNCS_H
#define FILE_FUNCS_H
#include "file_types.h"

using ptr = typename std::shared_ptr<PyObject>;
using cptr = typename std::shared_ptr<const PyObject>;

template<class Type, class ...oTypes>
ptr TryAdd(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TrySubtract(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryMultiply(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryDivide(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryMinus(const cptr& lhs);

template<class Type, class ...oTypes>
ptr TryInplaceAdd(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryInplaceSubtract(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryInplaceMultiply(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryInplaceDivide(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TrySize(const cptr& lhs);

ptr TryLower(const cptr& lhs);

ptr TryUpper(const cptr& lhs);

ptr TryTitle(const cptr& lhs);

template<class Type, class ...oTypes>
ptr TryIsEqual(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryNotEqual(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsGreater(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsLess(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsGreaterOrEqual(const cptr& lhs, const cptr& rhs);

template<class Type, class ...oTypes>
ptr TryIsLessOrEqual(const cptr& lhs, const cptr& rhs);

ptr TryNot(const cptr& lhs);

ptr TryAnd(const cptr& lhs, const cptr& rhs);

ptr TryOr(const cptr& lhs, const cptr& rhs);

ptr TryAppend(const ptr& list, const ptr& rhs);

ptr TryInsert(const ptr& list, const ptr& rhs, const cptr& obj);

ptr TryClear(const ptr& list);

ptr TryCopy(const cptr& list);

ptr TryExtend(const ptr& lhs, const ptr& rhs);

std::shared_ptr<PyFunction> make_function(const ptr& code, const ptr& name);

template<class Type, class ...oTypes>
ptr TryAdd(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl + *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryAdd<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TrySubtract(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl - *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TrySubtract<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryMultiply(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl * *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryMultiply<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryDivide(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl / *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryDivide<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryMinus(const cptr& lhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(-(*pl));
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryMinus<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TryInplaceAdd(const ptr& lhs, const cptr& rhs){
    Type * pl = dynamic_cast<Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        (*pl)+=(*pr);
        return lhs;
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryAdd<oTypes...>(lhs, rhs);
    }
};

/*
template<class Type, class ...oTypes>
ptr TryInplaceSubtract(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl-=*pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TrySubtract<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryInplaceMultiply(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl*=*pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryMultiply<oTypes...>(lhs, rhs);
    }
};

template<class Type, class ...oTypes>
ptr TryInplaceDivide(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl/=*pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryDivide<oTypes...>(lhs, rhs);
    }
};
*/
template<class Type, class ...oTypes>
ptr TrySize(const cptr& lhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    if(pl != nullptr){
        auto b = dynamic_cast<const Int*>(pl->size())->value;
        return std::make_shared<Int>(std::get<Int::val_type>(b));
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TrySize<oTypes...>(lhs);
    }
};

template<class Type, class ...oTypes>
ptr TryIsEqual(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl == *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsEqual<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryNotEqual(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl != *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryNotEqual<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsGreater(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl > *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsGreater<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsLess(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl < *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsLess<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsGreaterOrEqual(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl >= *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsGreaterOrEqual<oTypes...>(lhs, rhs);
    }
}

template<class Type, class ...oTypes>
ptr TryIsLessOrEqual(const cptr& lhs, const cptr& rhs){
    const Type * pl = dynamic_cast<const Type*>(lhs.get());
    const Type * pr = dynamic_cast<const Type*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl <= *pr);
    }else if constexpr (sizeof...(oTypes) == 0) {
        return {nullptr};
    }else{
        return TryIsLessOrEqual<oTypes...>(lhs, rhs);
    }
}

#endif // FILE_FUNCS_H