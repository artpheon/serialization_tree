#include "main.hpp"

CharArrayHolder::CharArrayHolder(const char* arr) {
    std::memset(this->innerArray, '\0', sizeof(this->innerArray));
    std::memcpy(this->innerArray, arr, sizeof(this->innerArray));
}

void CharArrayHolder::serialize(std::ostream& os) {
    os << "c" << this->innerArray;
    for (auto const& x: this->children) {
        x->serialize(os);
    }
    os << MARKER;
}

void CharArrayHolder::deserialize(std::istream& is) {
    
}


void CharArrayHolder::describe() const {
    std::cout << "Element is a CharArrayHolder with value: |" << this->innerArray << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for(auto const& x: this->children) {
            x->describe();
    }
}