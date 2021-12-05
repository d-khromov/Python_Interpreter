#include "type_funcs.h"

ptr TryLower(const cptr& lhs){
    const String * pl = dynamic_cast<const String*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->lower());
    }
    return {nullptr};
};

ptr TryUpper(const cptr& lhs){
    auto * pl = dynamic_cast<const String*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->upper());
    }
    return {nullptr};
};

ptr TryTitle(const cptr& lhs){
    const String * pl = dynamic_cast<const String*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(pl->title());
    }
    return {nullptr};
};

ptr TryNot(const cptr& lhs){
    const Bool * pl = dynamic_cast<const Bool*>(lhs.get());
    if(pl != nullptr){
        return std::shared_ptr<PyObject>(!(*pl));
    }
    return {nullptr};
}

ptr TryAnd(const cptr& lhs, const cptr& rhs){
    const Bool * pl = dynamic_cast<const Bool*>(lhs.get());
    const Bool * pr = dynamic_cast<const Bool*>(rhs.get());
    if(pl != nullptr && pr != nullptr){
        return std::shared_ptr<PyObject>(*pl && *pr);
    }
    return {nullptr};
}

ptr TryOr(const cptr& lhs, const cptr& rhs){
    const Bool * pl = dynamic_cast<const Bool*>(lhs.get());
    const Bool * pr = dynamic_cast<const Bool*>(rhs.get());
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