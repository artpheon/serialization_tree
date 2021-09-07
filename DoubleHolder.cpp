#include "main.hpp"

DoubleHolder::DoubleHolder(double d) {
    this->innerDouble = d;
}

std::size_t DoubleHolder::write(std::ostream& o, void* value) {
    const auto pos = o.tellp();
    o.write(reinterpret_cast<const char*>(&innerDouble), sizeof(innerDouble));
    return static_cast<std::size_t>(o.tellp() - pos);
}
