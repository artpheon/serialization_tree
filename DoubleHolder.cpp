#include "main.hpp"

DoubleHolder::DoubleHolder(double d) {
    this->innerDouble = d;
}

void DoubleHolder::serialize(std::ostream& os) override {
    os << DBL_MARK;
    os.write(reinterpret_cast<const char*>(&innerDouble), sizeof(double));
    os << STOP;
    write_children(os);
}

BaseHolder* DoubleHolder::deserialize(std::istream& is) {
    double t = 0.0;
    is.read(&t, sizeof(double));
    is.read(nullptr, 1);
    BaseHolder* ret = new DoubleHolder(t);
    return ret;
}

void DoubleHolder::describe() const {
    std::cout << "ELement is a DoubleHolder with value: |" << this->innerDouble << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for(auto const& x: this->children) {
            x->describe();
    }
}