#include "type_funcs.h"

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

std::shared_ptr<PyFunction> make_function(const ptr& code, const ptr& name){

    return std::make_shared<PyFunction>(
            dynamic_cast<PyCodeObject*>(code.get()),
            std::get<std::string>(dynamic_cast<String*>(name.get())->value)
    );
}