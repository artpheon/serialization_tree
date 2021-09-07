#include "main.hpp"

CharArrayHolder::CharArrayHolder(const char* arr) {
    std::memset(this->innerArray, '\0', sizeof(this->innerArray));
    std::memcpy(this->innerArray, arr, sizeof(this->innerArray));
}

std::size_t CharArrayHolder::write(std::ostream& o, void* value) {
    const auto pos = o.tellp();
    o.write(reinterpret_cast<const char*>(&innerArray), sizeof(innerArray));
    return static_cast<std::size_t>(o.tellp() - pos);
}