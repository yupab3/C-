#include <iostream>

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