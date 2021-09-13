#include "main.hpp"

DoubleHolder::DoubleHolder(double d) {
    this->innerDouble = d;
}

void DoubleHolder::serialize(std::ostream& os) {
    os << DBL_MARK;
    os.write(reinterpret_cast<const char*>(&innerDouble), sizeof(double));
    //os << STOP;
    write_children(os);
}


void DoubleHolder::describe() {
    std::cout << "ELement is a DoubleHolder with value: |" << this->innerDouble << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for(auto const& x: this->children) {
            x->describe();
       }
    }
}