#include <iostream>

/*
class A{
public:
    int x;
    int z;
};

class B{
public:
    int y;
};

int main(){
    char *dd = reinterpret_cast<char*>(1); // C++에서 C스타일 캐스팅을 수행하는 reinterpret_cast
    char *cdd = (char*)1;// C 스타일
    // std::cout << "dd = " << dd << '\n'; -> 비정상적인 호출로 segfault 발생!!
    char* dd1 = reinterpret_cast<char*>(const_cast<char*>("abcd")); //컴파일 가능, const_cast를 통해서 리터럴의 불변성을 제거하지만 진짜로 변경할 순 없음 상수화가 남아있는 상태. 컴파일 단계에서만 마치 상수화 되지 않은 변수처럼 취급함.
    A& a = *new A;
    a.x = 1;
    B& b = reinterpret_cast<B&>(a); // 레퍼런스로서 reinterpret_cast를 사용하는 경우
    std::cout << "b->y = " << b.y << '\n';
    A& c = *new A;
    c.x = 3;
    c.z = 4;
    B& d = reinterpret_cast<B&>(c); // 포인터로서 reinterpret_cast를 사용하는 경우
    std::cout << "b->y = " << d.y << '\n';
    //위와 같이 reinterpret_cast의 경우 상속도 아니고, 두 클래스 사이에서 묵시적 변환을 지원해주는 사용자 정의 변환이 없더라도 변환을 수행하며
    //심지어 두 포인터가 가리키는 객체의 크기가 다른 경우에도 무시하고 변환을 수행한다. 다운캐스팅이건 업캐스팅이건 reinterpret_cast는 아무것도 고려하지 않는다. 즉 책임은 사용자에게 있다!!!
    return 0;
}
*/

/*
int alltime_i = 1;

struct type
{
    int i;

    type(): i(3) {}
    void a(int v) const
    {
        this->f(v); // 상수 함수 호출!!
        const_cast<type*>(this)->f(v); // this의 비상수화 -> 비상수 함수 호출!!
    }
    void f(int v)
    {
        std::cout << "비상수 함수 호출\n";
    }
    void f(int v) const
    {
        std::cout << "상수 함수 호출\n";
        alltime_i = 2; // 전역변수는 const의 영향을 받지 않는 것 처럼 보인다. 왜?
        std::cout << alltime_i << '\n'; // 실제로 출력도 된다!!
        // this->i = v;                 // 함수에 적용되는 const 한정자가 실제로 하는 일에 대한 유추가 가능한 문장이다.
        const_cast<type*>(this)->i = v; // OK! 멤버 함수가 가지는 특성인 본인의 인스턴스를 가리키는 this에 const를 걸어줬기 때문에 const함수가 모든 변수에 한정자가 적용된 것 처럼 동작했다는 것을 알 수 있다.
        // 따라서 this의 const만 떼주면 모든 변수에 대해서 변경이 가능하며, 만약 변수에도 const가 걸려있다면 변경이 불가능하다.
        // 위 문장에서 const_cast로 제거한 const 한정자는 this에 국한되기 때문에 this를 통해 호출한 i에 적용되어있는 한정자는 여전히 동작하기 때문이다.
    }
};

const int*	tmpf(const int& tmpj){
	std::cout << &tmpj << '\n';
	return &tmpj;
}

int main()
{
    int i = 3;                 // 일반 변수로 i 선언
    const_cast<int&>(i) = 1; // const_cast의 결과가 되는 형식에 대해서만 포인터 또는 레퍼런스가 와야하고, 소괄호 안에 오는 캐스팅 대상은 일반 변수도 사용할 수 있다! (의미는 없음 ㅎ)
    const int& rci = i;
	int	&ii = i;
    const_cast<int&>(ii) = 4; // OK: 일반 변수에 이어 일반 레퍼런스 또한 적용 가능!
	i = 4;
    std::cout << "i = " << i << ", ii = " << ii << '\n';

    const type* tt = new type;
    tt->f(4); // 상수 멤버 함수 호출
    const_cast<type*>(tt)->f(4); // 비상수 멤버 함수 호출
    tt->a(4); // 상수/비상수 멤버 함수를 상수 멤버 함수 안에서 구분하여 호출!
    std::cout << "type::i = " << tt->i << '\n';

    const int j = 3; // j는 const 정수
    const int& jref = j;
	std::cout << &j << '\n';
    // int* pj = const_cast<int*>(tmpf(j)); // 입력받은 const int의 주소를 포인터 형식으로 리턴하는 함수 실제로 j의 어드레스를 반환받아 값을 변경할 수 있다. 하지만 j에 저장된 값을 출력할 때도 바뀔까?
    int& pj = const_cast<int&>(j);
    pj = 4;      // undefined behavior
	std::cout << pj << '\n';
	std::cout << pj << j << jref; // pj, j, jref는 실제로 같은 공간을 참조하고 있다. 그런데 왜 434라는 출력이 나올까?
    // 컴파일러는 const 로 선언된 포인터/레퍼런스가 아닌 변수에 대해서 컴파일 하는 과정에서 미리 문맥을 치환한다.
    // 즉 jref와 pj는 레퍼런스/포인터 이기 때문에 pj, jref는 주소 공간에 저장된 값을 호출하는 역참조로 컴파일 되어 4가 출력되고, j는 단순 치환으로 이미 3이 들어간 상태로 코드가 실행된 것이다!!!

    void (type::* pmf)(int) const = &type::f; // 멤버 함수 포인터 pmf를 선언하고 상수화를 제거하려고 하면 에러가 발생한다.
    // const_cast<void(type::*)(int)>(pmf);   // 함수 포인터, 멤버 함수 포인터에 대해서는 const_cast 가 동작하지 않는다.
    //위 예제에서 마치 되는 것 처럼 테스트하고 있지만 위 예제는 this의 상수화를 제거했을 뿐 const_cast라는 캐스팅 기법이 함수에 대한 상수화 제거를 지원하는 것이 아니다~
}
*/

/*
class   SoSimple{
public:
    virtual void    ShowSimpleInfo(){
        std::cout << "SoSimple Base Class" << std::endl;
    }
};

class   SoComplex : public SoSimple{
public:
    void    ShowSimpleInfo(){
        std::cout << "SoComplex Base Class" << std::endl;
    }
};

int main(void){
    SoSimple* simPtr = new SoComplex;
    SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
    comPtr->ShowSimpleInfo();
    return 0;
}
*/

/*
int main(){
    float fdd = static_cast<float>(1); //컴파일 가능
    char dd = static_cast<char>(1); //컴파일 가능
    char* dd1 = static_cast<char*>(const_cast<char*>("abcd")); //컴파일 가능, const_cast를 통해서 리터럴의 불변성을 제거하지만 진짜로 변경할 순 없음 상수화가 남아있는 상태. 컴파일 단계에서만 마치 상수화 되지 않은 변수처럼 취급함.

    std::cout << dd1 << " " << *dd1 << " " << *(dd1 + 1) << " " << *(dd1 + 3);
    *dd1 = 'c'; // 컴파일은 가능하나 RO 영역에 저장된 데이터에 쓰기작업 시도로 인한 bus error 발생! 리터럴은 RO 영역에 저장된 상태로 어드레스를 rvalue로서 뱉기 때문이다.
    std::cout << dd1[1];
    return 0;
}
*/

/*
class   SoSimple{
public:
    int x;
    virtual void    ShowSimpleInfo(){
        std::cout << "SoSimple Base Class" << std::endl;
    }
};

class   SoComplex : virtual public SoSimple{
public:
    void    ShowSimpleInfo(){
        std::cout << "SoComplex Base Class" << std::endl;
    }
};

int main(void){
    SoComplex C;
    int a = 4;
    SoSimple* S = &C;
    int b = 5;
    std::cout << &C << " " << S;
    // SoSimple* simPtr = new SoComplex;
    // SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
    // comPtr->ShowSimpleInfo();
    // simPtr->ShowSimpleInfo();
    return 0;
}
*/

/*
using namespace std;

class CMyData
{
public:
	CMyData(int x, int y) : nData(x), yData(y)
	{
		cout << "변환 생성자 호출" << endl;
	}

	int GetData() const
	{
		return nData;
	}

private:
	int nData;
    int yData;
};

void TestFunc(const CMyData &rhs) // 분명 TestFunc 함수는 매개값으로 CMyData 객체의 참조를 받는다.
{
	cout << "TestFunc(): " << rhs.GetData() << endl;
}

int main()
{
	CMyData a(100, 100);
	TestFunc(a); // 일반적인 함수 호출 경우

	TestFunc(1000, 1000); // 인자값으로 1000을 넣었는데도 컴파일 오류가 발생하지 않는다.
	return 0;
}
*/

/*
class Base
{
public:
    virtual ~Base();
};

Base::~Base(){
    return ;
}

class Derived : public Base
{
public:
    virtual ~Derived();
};

Derived::~Derived(){
    return ;
}

int main()
{
    // Base* b = nullptr;
    // Derived* d = new Derived();
    // b = d; // Don't need a cast to go up the inheritance hierarchy
    // d = static_cast<Derived*>(b); // Need a cast to go down the hierarchy

    Base base;
    Derived derived;
    Base& br = derived;
    Derived& dr = static_cast<Derived&>(br);

    Base* b = new Base();
    Derived* d = static_cast<Derived*>(b);
}
*/

/*
int main(void){
    const int& tmp = 10;
    const int& e = const_cast<int&>(tmp)++;
    std::cout << tmp << ", " << e;
    "test" = 1;
    return 0;
}
*/

/*
struct type
{
    int i;

    type(): i(3) {}

    void f(int v) const
    {
        // this->i = v;                 // compile error: this is a pointer to const
        const_cast<type*>(this)->i = v; // OK as long as the type object isn't const
    }
};

const int*	tmpf(const int& tmpj){
	std::cout << &tmpj << '\n';
	return &tmpj;
}

int main()
{
    int i = 3;                 // i is not declared const
    const int& rci = i;
	int	&ii = i;
    const_cast<int&>(ii) = 4; // OK: modifies i
	i = 4;
    std::cout << "i = " << i << '\n';

    type t; // if this was const type t, then t.f(4) would be undefined behavior
    t.f(4);
    std::cout << "type::i = " << t.i << '\n';

    const int j = 3; // j is declared const
	std::cout << &j << '\n';
    int* pj = const_cast<int*>(tmpf(j));
    *pj = 4;      // undefined behavior
	std::cout << pj << '\n';
	std::cout << *pj << j;

    void (type::* pmf)(int) const = &type::f; // pointer to member function
    // const_cast<void(type::*)(int)>(pmf);   // compile error: const_cast does
                                              // not work on function pointers
}
*/

/*
static int aa = 10;
int& foo() {
    aa++;
    return aa;
}
int foo2(){
    return aa;
}

//좌측값 (Lvalue)
int main(){
    int a = 10,b=10,c=10;
    int *j = &a; //참조 가능하기 때문에 a는 좌측값(Lvalue)
    foo() = 43; //foo()는 좌측값(Lvalue)
    int *ptr1 = &foo(); //&foo()가능하기 때문에 좌측값(Lvalue)
    ++a;//a는 lvalue, pre-increasement, pre-decreasement
    int cc[4];
    std::cout << *ptr1 << " " << aa << " " << cc[1] << std::endl;//c[1]도 lvalue
    a ? b : c;// a ? b : c의 반환값은 b 또는 c이므로 lvalue
}
*/

/*
class Temp{
public:
	int a;
	// ...
	// ...
	Temp(int _a);
};

Temp::Temp(int _a){
	a = _a;
}

void	printTemp(const Temp a){
	std::cout << a.a;
}

int main(void){
	Temp	aa = 1; // -> Temp aa(1); : implicit!! 
	const int	bb = static_cast<int>(2);
	// Temp	bb(1); // -> 정상 실행
	printTemp(1); // -> printTemp(Temp(1)) : implicit!!
	
	// printTemp(aa); // -> 정상 실행
	return 0;
}
*/


/*
// class temp{
// 	int a;
// 	// mutable int a;
// 	int b;
// 	// ...
// 	// ...
// 	void	f(int _a, int _b) const;
// };

// void	temp::f(int _a, int _b) const{
// 	// a = _a;
// 	// b = _b;
// 	int aa;
// 	aa = _a;
// 	std::cout << a << _a << b << _b;
// }

int main(void){
	const int	a = 1;
	int b = 2;
	const int*	pa = &a;
	int* const	pb = &b;
	// *pa = 2;
	pa = &b;
	// pb = &a;
	*pb = 3;
}
*/