#include "main.hpp"

void IntHolder::serialize(std::ostream& os) override {
    os << INT_MARK;
    os.write(reinterpret_cast<const char*>(&innerInt), sizeof(std::int32_t));
    os << STOP;
    write_children(os);
}

BaseHolder* IntHolder::deserialize(std::istream& is) {
    std::int32_t t = 0;
    is.read(&t, sizeof(std::int32_t));
    is.read(nullptr, 1);
    BaseHolder* ret = new IntHolder(t);
    return ret;
}

IntHolder::IntHolder(std::int32_t i) {
    this->innerInt = i;
}



void IntHolder::describe() const {
    std::cout << "Element is a IntHolder with value: |" << this->innerInt << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for (auto const& x: this->children) { 
            x->describe();
    }
}