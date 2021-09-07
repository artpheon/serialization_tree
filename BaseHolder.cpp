#include "main.hpp"

BaseHolder::~BaseHolder() {}

BaseHolder::BaseHolder()
: parent(nullptr)
, children(0)
{}

BaseHolder*    BaseHolder::setParent(BaseHolder* p) {
    this->parent = p;
    return this;
}

BaseHolder*    BaseHolder::addChild(BaseHolder* ch) {
    children.push_back(ch);
    return this;
}
