#include "main.hpp"

CharArrayHolder::CharArrayHolder() = default;

CharArrayHolder::~CharArrayHolder() {
	for (auto& x: this->children) {
		delete x;
	}
}

CharArrayHolder::CharArrayHolder(const char* arr)
: innerArray("000000000") {
    std::memcpy(this->innerArray, arr, sizeof(this->innerArray));
}

void CharArrayHolder::serialize(std::ostream& os) {
    os << CHR_MARK;
    os.write(innerArray, sizeof innerArray);
    write_children(os);
}

void CharArrayHolder::describe() {
    std::cout << "Element is a CharArrayHolder with value: |" << this->innerArray << "|. It has " << this->children.size() << " children." << std::endl;
    if (!this->children.empty()) {
        for(auto const& x: this->children) {
            x->describe();
        }
    }
}

CharArrayHolder::CharArrayHolder(const CharArrayHolder &rhs)
: BaseHolder(rhs) {
	*this = rhs;
}

CharArrayHolder &CharArrayHolder::operator=(const CharArrayHolder &rhs) {
	if (this != &rhs) {
		std::memcpy(this->innerArray, rhs.innerArray, sizeof this->innerArray);
	}
	return *this;
}

