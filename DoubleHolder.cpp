#include "main.hpp"

DoubleHolder::DoubleHolder(double d) {
    this->innerDouble = d;
}

void DoubleHolder::serialize(std::ostream& os) override {
    os << this->innerDouble;
    for (auto const& x: this->children) {
        x->serialize(os);
    }
    os << MARKER;
}

void DoubleHolder::describe() const {
    std::cout << "ELement is a DoubleHolder with value: |" << this->innerDouble << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for(auto const& x: this->children) {
            x->describe();
    }
}