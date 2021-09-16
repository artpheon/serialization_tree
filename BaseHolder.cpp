#include "main.hpp"

BaseHolder::~BaseHolder() = default;

BaseHolder::BaseHolder()
: children(0)
, _parent(nullptr)
{}

void BaseHolder::write_children(std::ostream& os) {
    if (!this->children.empty()) {
        for (auto& x: this->children) {
			os << DOWN;
			x->serialize(os);
			os << UP;
        }
    }
}

BaseHolder*	BaseHolder::parent() {
	return _parent;
}

// node(int 1)
//  ||
//  node(int 2011)
//  ||
//  cFULCRUM;>cLINUX

BaseHolder* BaseHolder::_deserialize_(std::istream& is, char c) {
	BaseHolder* node = nullptr;
	if (c == INT_MARK) {
		std::int32_t t = 0;
		is.read(reinterpret_cast<char *>(&t), sizeof(std::int32_t));
		node = new IntHolder(t);
	}
	else if (c == DBL_MARK) {
		double t = 0.0;
		is.read(reinterpret_cast<char *>(&t), sizeof(double));
		node = new DoubleHolder(t);
	}
	else if (c == CHR_MARK) {
		char buf[10] = {0};
		is.read(buf, 10);
		node = new CharArrayHolder(buf);
	}
	else
		std::cerr << "could not _deserialize_ element\n";
	return node;
}

BaseHolder* BaseHolder::deserialize(std::istream& is) {
	BaseHolder* root = nullptr, *where = nullptr;
	char c = '\0';

	is.read(&c, 1);
	root = _deserialize_(is, c);
	where = root;
	if (root == nullptr)
		return root;

	for (BaseHolder* ptr = nullptr;!is.eof();) {
		is.read(&c, 1);
		if (c == DOWN) {
			is.read(&c, 1);
			ptr = _deserialize_(is, c);
			if (ptr == nullptr)
				break ;
			where->addChild(ptr);
			where = ptr;
		}
		else if (c == UP) {
			where = where->parent();
		}
		else {
			ptr = _deserialize_(is, c);
			where->parent()->addChild(ptr);
		}
	}
	return root;
}

void    BaseHolder::setParent(BaseHolder* p) {
    this->_parent = p;
}

BaseHolder*    BaseHolder::addChild(BaseHolder* ch) {
    children.push_back(ch);
    ch->setParent(this);
    return this;
}

BaseHolder::BaseHolder(const BaseHolder &rhs) {
	*this = rhs;
}

BaseHolder &BaseHolder::operator=(const BaseHolder &rhs) {
	if (this != &rhs) {
		this->children = rhs.children;
		this->_parent = rhs._parent;
	}
	return *this;
}
