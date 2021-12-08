#include "frame.h"

Frame::Frame(std::shared_ptr<PyCodeObject> code,
             std::unordered_map<std::string, ptr> globals,
             std::unordered_map<std::string, ptr>  locals,
             Frame* prev_frame):
        globals(std::move(globals)), locals(std::move(locals)), code(code), prev_frame(prev_frame), value_stack({}), cur_instr(0), running(false){
    if(prev_frame){
        builtins=prev_frame->builtins;
    }
}

void Frame::Push(const ptr& obj) {
    value_stack.push_back(obj);
}

ptr Frame::Pop(){
    ptr tmp = value_stack.back();
    value_stack.pop_back();
    return tmp;
}

ptr Frame::Top(){
    return value_stack.back();
}

ptr Frame::Peek(size_t n){
    return *std::prev(value_stack.end()-n);
}

void Frame::SetTop(const ptr& obj) {
    value_stack.back() = obj;
}

void Frame::Set(const ptr& obj, size_t n) {
    *std::prev(value_stack.end()-n) = obj;
}
