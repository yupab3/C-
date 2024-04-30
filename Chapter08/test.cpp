#include <iostream>

class test2{
public:
	std::string name;
	void f(void);
	~test2(void);
	int num;
};

test2::~test2(void){
	std::cout << "test2 dest\n";
}

void test2::f(void){
	std::cout << "test2\n";
}

class test1{
public:
	void f(void);
	~test1(void);
	int num;
};

test1::~test1(void){
	std::cout << "test1 dest\n";
}

void test1::f(void){
	std::cout << "test1\n";
}

class tester : public test1, protected test2{
public:
	void f2(void);
	~tester(void);
};

tester::~tester(void){
	std::cout << "tester dest\n";
}

void tester::f2(void){
	test1::f();
	test2::f();
	std::cout << "tester\n";
}

int	main(void){
	// test *ptr = new tester();
	// // tester *ptr2 = (tester *)ptr;
	// // ptr2->~tester();
	// ptr->~test();

	tester t1;
	
	return 0;
}