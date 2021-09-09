#include "main.hpp"

BaseHolder::~BaseHolder() {}

BaseHolder::BaseHolder()
: children(0)
{}

BaseHolder*    BaseHolder::setParent(BaseHolder* p) {
    return this;
}

BaseHolder*    BaseHolder::addChild(BaseHolder* ch) {
    children.push_back(ch);
    return this;
}
