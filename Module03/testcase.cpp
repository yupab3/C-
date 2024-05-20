#include <iostream>

class testA{
public:
	int num_A;
	// virtual ~
	void Showname(){
		std::cout << "A\n";
	}
	testA(void);
	virtual ~testA();
};

testA::testA(void){};
testA::~testA(void){};

class testB: virtual public testA{
public:
	int num_B;
	void Showname(){
		std::cout << "B\n";
	}
	testB(void);
	virtual ~testB();
};

testB::testB(void){};
testB::~testB(void){};

class testC: virtual public testA{
public:
	int num_C;
	void Showname(){
		std::cout << "C\n";
	}
	testC(void);
	virtual ~testC();
};

testC::testC(void){};
testC::~testC(void){};

class testD: virtual public testB, virtual public testC{
public:
	int num_D;
	void Showname(){
		std::cout << "D\n";
	}
	testD(void);
	virtual ~testD();
};

testD::testD(void){};
testD::~testD(void){};

class testE: virtual public testB, virtual public testC{
public:
	int num_E;
	void Showname(){
		std::cout << "E\n";
	}
	testE(void);
	virtual ~testE();
};

testE::testE(void){};
testE::~testE(void){};

class testF: public testD, public testE{
public:
	int num_F;
	void Showname(){
		std::cout << "F\n";
	}
	testF(void);
	virtual ~testF();
};

testF::testF(void){};
testF::~testF(void){};

int	main(void){
	testA	*Aptr = new testF;
	testB	*Bptr = dynamic_cast<testB*>(Aptr);
	testC	*Cptr = dynamic_cast<testC*>(Aptr);
	testD	*Dptr = dynamic_cast<testD*>(Aptr);
	testE	*Eptr = dynamic_cast<testE*>(Aptr);
	testF	*Fptr = dynamic_cast<testF*>(Aptr);
	Aptr->Showname();
	Bptr->Showname();
	Cptr->Showname();
	Dptr->Showname();
	Eptr->Showname();
	Fptr->Showname();

	// testF f1;
	// f1.num_A;
	// f1.num_B;
	// f1.num_C;
	// f1.num_D;
	// f1.num_E;
	// f1.num_F;
}