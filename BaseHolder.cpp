#include "main.hpp"

BaseHolder::~BaseHolder() {}

BaseHolder::BaseHolder()
: children(0)
{}

void BaseHolder::write_children(std::ostream& os) {
    if (this->children.size() > 0) {
        os << DOWN;
        for (auto& x: this->children) {
            x->serialize(os);
        }
        os << UP;
    }
}

// i1;>i2011;>cFULCRUM;>cLINUX;i7<<<cC++;d3.14;>cTEST;i9;i6;

// node(int 1)
//  ||
//  node(int 2011)
//  ||
//  cFULCRUM;>cLINUX
BaseHolder* BaseHolder::deserialize(std::istream& is, BaseHolder* parent, char c) {
    BaseHolder* node = nullptr;
    if (!c)
    	is.read(&c, 1);

    if (c == INT_MARK) {
        std::int32_t t = 0;
        is.read(reinterpret_cast<char *>(&t), sizeof(std::int32_t));
        node = new IntHolder(t);
        is.read(&c, 1);
        if (c == DOWN) {
			is.read(&c, 1);
            node->addChild(BaseHolder::deserialize(is, node, c));
            return node;
        }
        else if (c == UP)
			return node;
        else if (is.eof()) {
            return node;
        }
        else {
            parent->addChild(BaseHolder::deserialize(is, parent, c));
            return node;
        }
    }
    else if (c == DBL_MARK) {
        double t = 0.0;
        is.read(reinterpret_cast<char *>(&t), sizeof(double));
        node = new DoubleHolder(t);
        is.read(&c, 1);
        if (c == DOWN) {
			while (c == DOWN) {
				node->addChild(BaseHolder::deserialize(is, node, c));
			}
            return node;
        }
        else if (c == UP)
            return node;
        else if (is.eof()) {
            return node;
        }
        else {
            parent->addChild(BaseHolder::deserialize(is, parent, c));
            return node;
        }
    }
    else if (c == CHR_MARK) {
        char buf[10] = {0};
        is.read(buf, 10);
        node = new CharArrayHolder(buf);
        is.read(&c, 1);
        if (c == DOWN) {
			is.read(&c, 1);
            node->addChild(BaseHolder::deserialize(is, node, c));
            return node;
        }
        else if (c == UP)
            return node;
        else if (is.eof()) {
            return node;
        }
        else {
            parent->addChild(BaseHolder::deserialize(is, parent, c));
            return node;
        }
    }
    else {
        exit(1);
    }
}

BaseHolder*    BaseHolder::setParent(BaseHolder* p) {
    return this;
}

BaseHolder*    BaseHolder::addChild(BaseHolder* ch) {
    children.push_back(ch);
    return this;
}
