#include "main.hpp"

std::size_t IntHolder::write(std::ostream& o, void* value) {
    const auto pos = o.tellp();
    o.write(reinterpret_cast<const char*>(&innerInt), sizeof(innerInt));
    return static_cast<std::size_t>(o.tellp() - pos);
}

IntHolder::IntHolder(std::int32_t i) {
    this->innerInt = i;
}