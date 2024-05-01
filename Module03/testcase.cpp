#include <iostream>

class testA{
public:
	int num_A;
	// virtual ~
	testA(void);
};

testA::testA(void){};

class testB: virtual public testA{
public:
	int num_B;
	testB(void);
};

testB::testB(void){};

class testC: virtual public testA{
public:
	int num_C;
	testC(void);
};

testC::testC(void){};

class testD: public testB, public testC{
public:
	int num_D;
	testD(void);
};

testD::testD(void){};

class testE: public testB, public testC{
public:
	int num_E;
	testE(void);
};

testE::testE(void){};

class testF: public testD, public testE{
public:
	int num_F;
	testF(void);
};

testF::testF(void){};

int	main(void){
	testF f1;
	f1.num_A;
	f1.num_B;
	f1.num_C;
	f1.num_D;
	f1.num_E;
	f1.num_F;
}