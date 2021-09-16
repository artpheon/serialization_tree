#include "main.hpp"

DoubleHolder::DoubleHolder() = default;

DoubleHolder::~DoubleHolder() {
	for (auto& x: this->children) {
		delete x;
	}
}

DoubleHolder::DoubleHolder(double d) {
    this->innerDouble = d;
}

void DoubleHolder::serialize(std::ostream& os) {
    os << DBL_MARK;
    os.write(reinterpret_cast<const char*>(&innerDouble), sizeof(double));
    write_children(os);
}

void DoubleHolder::describe() {
    std::cout << "ELement is a DoubleHolder with value: |" << this->innerDouble << "|. It has " << this->children.size() << " children." << std::endl;
    if (!this->children.empty()) {
        for(auto const& x: this->children) {
            x->describe();
       }
    }
}

DoubleHolder::DoubleHolder(const DoubleHolder &rhs)
: BaseHolder(rhs) {
	*this = rhs;
}

DoubleHolder &DoubleHolder::operator=(const DoubleHolder &rhs)
{
	if (this != &rhs) {
		this->innerDouble = rhs.innerDouble;
	}
	return *this;
}
