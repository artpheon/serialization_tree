#include "main.hpp"

using u32    = uint_least32_t;
using engine = std::mt19937;

double random_double() {
	double lower_bound = 0;
	double upper_bound = 10000;
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	std::default_random_engine re;
	return unif(re);
}

int random_int() {
	std::random_device os_seed;
	const u32 seed = os_seed();
	engine generator( seed );
	std::uniform_int_distribution< u32 > distribute( 0, 10000);
	return static_cast<int>(distribute( generator ));
}

BaseHolder* get_random_tree() {
	BaseHolder* root = new CharArrayHolder("ROOT");

	BaseHolder* left1 = new IntHolder(random_int());
	BaseHolder* left2 = new IntHolder(random_int());
	BaseHolder* left31 = new DoubleHolder(random_double());
	BaseHolder* left32 = new CharArrayHolder("LEFT");

	BaseHolder* mid1 = new CharArrayHolder("MID");
	BaseHolder* mid2 = new CharArrayHolder("NEXT");
	BaseHolder* mid3 = new DoubleHolder(random_double());

	BaseHolder* right1 = new CharArrayHolder("Start");
	BaseHolder* right2 = new IntHolder(random_int());
	BaseHolder* right31 = new IntHolder(random_int());
	BaseHolder* right32 = new DoubleHolder(random_double());
	BaseHolder* right4 = new CharArrayHolder("LAST");

	root->addChild(left1);
	left1->addChild(left2);
	left2->addChild(left31);
	left2->addChild(left32);

	root->addChild(mid1);
	mid1->addChild(mid2);
	mid2->addChild(mid3);

	root->addChild(right1);
	right1->addChild(right2);
	right2->addChild(right31);
	right2->addChild(right32);
	right32->addChild(right4);

	return root;
}

BaseHolder* get_filled_tree() {
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
	return l1v1;
}

int test1() {
    std::filebuf fb;
    fb.open ("example_tree", std::ios::out);
    std::ostream os(&fb);

    BaseHolder* tree = get_filled_tree();
    tree->serialize(os);

    fb.close();
    fb.open ("example_tree", std::ios::in);
    std::istream is(&fb);
    BaseHolder* deserialized = BaseHolder::deserialize(is);

    if (deserialized) {
    	std::cout << "Before:\n";
    	tree->describe();
    	std::cout << "\n\nAfter:\n";
    	deserialized->describe(); std::cout << std::endl;
    	std::cout << "\n" << std::endl;
    }
    else {
    	std::cerr << "failed to deserialize the tree\n";
    	delete tree;
    	exit(1);
    }
    delete tree; delete deserialized;
    return 0;
}

int test2() {
	std::filebuf fb;
	fb.open ("random_tree", std::ios::out);
	std::ostream os(&fb);

	BaseHolder* tree = get_random_tree();
	tree->serialize(os);

	fb.close();
	fb.open ("random_tree", std::ios::in);
	std::istream is(&fb);
	BaseHolder* deserialized = BaseHolder::deserialize(is);

	if (deserialized) {
		std::cout << "Before:\n";
		tree->describe();
		std::cout << "\n\nAfter:\n";
		deserialized->describe(); std::cout << std::endl;
		std::cout << "\n" << std::endl;
	}
	else {
		std::cerr << "failed to deserialize the tree\n";
		delete tree;
		exit(1);
	}
	delete tree; delete deserialized;
	return 0;
}

int main() {
	test1();
	test2();
	getchar();
	return 0;
}