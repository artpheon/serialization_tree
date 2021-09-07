#include "main.hpp"

int main() {
    std::filebuf fb;
    fb.open ("data", std::ios::out);
    std::ostream os(&fb);

    BaseHolder* val = new IntHolder(45);
    val->write(os, nullptr);
    BaseHolder* val2 = new CharArrayHolder("new text");
    val2->write(os, nullptr);
    BaseHolder* val3 = new DoubleHolder(66.6);
    val3->write(os, nullptr);

    fb.close();
    delete val;
    delete val2;
    delete val3;
    return 0;
}