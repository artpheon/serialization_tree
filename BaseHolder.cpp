#include "main.hpp"

BaseHolder::~BaseHolder() {}

BaseHolder::BaseHolder()
: children(0)
{}

void write_children(std::ostream& os) {
    if (children.size() > 0) {
        os << DOWN;
        for (auto& x: children) {
            x->serialize(os);
        }
        os << UP;
    }
}

BaseHolder*    BaseHolder::setParent(BaseHolder* p) {
    return this;
}

BaseHolder*    BaseHolder::addChild(BaseHolder* ch) {
    children.push_back(ch);
    return this;
}
