#include "main.hpp"

IntHolder::IntHolder() = default;

IntHolder::~IntHolder() {
	for (auto& x: this->children) {
		delete x;
	}
}

void IntHolder::serialize(std::ostream& os) {
    os << INT_MARK;
    os.write(reinterpret_cast<const char*>(&innerInt), sizeof(std::int32_t));
    write_children(os);
}

IntHolder::IntHolder(std::int32_t i) {
    this->innerInt = i;
}

void IntHolder::describe() {
    std::cout << "Element is a IntHolder with value: |" << this->innerInt << "|. It has " << this->children.size() << " children." << std::endl;
    if (!this->children.empty()) {
        for (auto const& x: this->children) { 
            x->describe();
        }
    }
}

IntHolder::IntHolder(const IntHolder &rhs)
: BaseHolder(rhs) {
	*this = rhs;
}

IntHolder &IntHolder::operator=(const IntHolder &rhs) {
	if (this != &rhs) {
		this->innerInt = rhs.innerInt;
	}
	return *this;
}
