#include "main.hpp"

void IntHolder::serialize(std::ostream& os) {
    os << INT_MARK;
    os.write(reinterpret_cast<const char*>(&innerInt), sizeof(std::int32_t));
    //os << STOP;
    write_children(os);
}


IntHolder::IntHolder(std::int32_t i) {
    this->innerInt = i;
}



void IntHolder::describe() {
    std::cout << "Element is a IntHolder with value: |" << this->innerInt << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for (auto const& x: this->children) { 
            x->describe();
        }
    }
}