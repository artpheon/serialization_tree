#include "main.hpp"

void IntHolder::serialize(std::ostream& os) override {
    os << this->innerInt;
    for (auto const& x: this->children) {
        x->serialize(os);
    }
    os << MARKER;
}

IntHolder::IntHolder(std::int32_t i) {
    this->innerInt = i;
}

void IntHolder::describe() const {
    std::cout << "Element is a IntHolder with value: |" << this->innerInt << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for(auto const& x: this->children) {
            x->describe();
    }
}