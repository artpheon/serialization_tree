#include "main.hpp"


int main() {
    std::filebuf fb;
    fb.open ("data", std::ios::out);
    std::ostream os(&fb);

    BaseHolder* l1v1 = new IntHolder(1);

    BaseHolder* l2v1 = new IntHolder(2011);
    BaseHolder* l2v2 = new CharArrayHolder("C++");
    BaseHolder* l2v3 = new DoubleHolder(3.14);

    BaseHolder* l3v1 = new CharArrayHolder("FULCRUM");
    BaseHolder* l3v2 = new CharArrayHolder("TEST");
    BaseHolder* l3v3 = new IntHolder(9);
    BaseHolder* l3v4 = new IntHolder(6);

    BaseHolder* l4v1 = new CharArrayHolder("LINUX");
    BaseHolder* l4v2 = new IntHolder(7);

    l1v1->addChild(l2v1);
    l1v1->addChild(l2v2);
    l1v1->addChild(l2v3);

    l2v1->addChild(l3v1);
    l3v1->addChild(l4v1);
    l3v1->addChild(l4v2);

    l2v3->addChild(l3v2);
    l2v3->addChild(l3v3);
    l2v3->addChild(l3v4);

    l1v1->describe();
    l1v1->serialize(os);

    fb.close();
    fb.open ("data", std::ios::in);
    std::istream is(&fb);
    BaseHolder* deserialized = nullptr;
    deserialized = BaseHolder::deserialize(is, deserialized, 0);

    delete l1v1;
    delete l2v1;
    delete l2v2;
    delete l2v3;
    delete l3v1;
    delete l3v2;
    delete l3v3;
    delete l3v4;
    delete l4v1;
    delete l4v2;
    return 0;
}