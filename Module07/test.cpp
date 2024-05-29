#include <iostream>

#include <iostream>

template <int n>
struct Fibonacci
{
	enum
	{
		value = Fibonacci<n-1>::value + Fibonacci<n-2>::value
	};
};

template <>
struct Fibonacci<0>
{
	enum { value = 1 };
};
template <>
struct Fibonacci<1>
{
	enum { value = 1 };
};

int main()
{
	std::cout << Fibonacci<46>::value << std::endl;
	return 0;
}

/*
template <typename T>
class	testClass
{
public:
	T	data;

	void	printData(void){
		std::cout << data << " output of T \n";
	}
};

template <>
class	testClass<std::string>
{
public:
	std::string	data;

	void	printData(void){
		std::cout << data << " output of std::string from complete specialisation\n";
	}
};

template <typename T>
class	testClass<T*>
{
public:
	T	*data;

	void	printData(void){
		std::cout << data << " output of T* from typename T partially specialisation \n";
	}
};

int	main(void)
{
	testClass<int> classInt;
	testClass<std::string> classString;
	testClass<char*> classCharStr;

	classInt.data = 1;
	classString.data = "stringClass";
	classCharStr.data = "tempStr";

	classInt.printData();
	classString.printData();
	classCharStr.printData();
	return 0;
}
*/

/*
template <typename T, typename Q, typename R> void bar(T a, Q b, R c) { std::cout << "bar(T, T, T)\n"; a = 2; std::cout << a;};
template <typename T, typename Q, typename R> void bar(const T& a, const Q& b, const R& c) { std::cout << "bar(T&, T&, T&)\n"; a = 2;}; // overload of bar(T)


int	main(void)
{
	int a = 1;
	bar(1, 3, 2); // 1
	bar(a, a, a); // 2
}
*/

/*
template <typename T, typename Q, typename R> void bar(T a, Q b, R c) { std::cout << "bar(T, T, T)\n"; a = 2; std::cout << a;};
// template <typename T, typename Q, typename R> void bar(T*, Q, R) { std::cout << "bar(T*, T, T)\n"; }; // overload of bar(T)
// template <typename T, typename Q, typename R> void bar(T, Q*, R) { std::cout << "bar(T, T*, T)\n"; }; // overload of bar(T)
// template <typename T, typename Q, typename R> void bar(T, Q, R*) { std::cout << "bar(T, T, T*)\n"; }; // overload of bar(T)
// template <typename T, typename Q, typename R> void bar(T*, Q*, R) { std::cout << "bar(T*, T*, T)\n"; }; // overload of bar(T)
// template <typename T, typename Q, typename R> void bar(T*, Q, R*) { std::cout << "bar(T*, T, T*)\n"; }; // overload of bar(T)
// template <typename T, typename Q, typename R> void bar(T, Q*, R*) { std::cout << "bar(T, T*, T*)\n"; }; // overload of bar(T)
template <typename T, typename Q, typename R> void bar(T& a, Q& b, R& c) { std::cout << "bar(T&, T&, T&)\n"; a = 2;}; // overload of bar(T)

// template <typename T> void foo(T) { std::cout << "foo(T)\n";};
// template <typename T> void foo(T*) { std::cout << "foo(T*)\n"; }; // overload of foo(T)
// template <>           void foo<int*>(int*) { std::cout << "foo<int*>(int*)\n specialisation of foo(T)\n"; }; // specialisation of foo(T)
// template <>           void foo<int>(int) { std::cout << "foo<int>(int)\n specialisation of foo(T)\n"; }; // specialisation of foo(T)
// template <>           void foo<int>(int*) { std::cout << "foo<int>(int*)\n specialisation of foo(T*)\n"; }; // specialisation of foo(T*)

int	main(void)
{
	int a = 1;
	int& a1 = a;
	int& a2 = a;
	int& a3 = a;
	bar(1, 3, 2);
	bar(a, a, a);
	// foo<int*>(new int);
	// foo(new int);
	// foo(3); // calls foo<int>(int*);
}
*/

/*
template <typename T>
void myFunc(T t)
{
	std::cout << "primary template function" << std::endl;
};

template <>
void myFunc<int>(int number)
{
	std::cout << "full specialization template function" << std::endl;
}

int	main(void)
{
	myFunc(1.0);
	myFunc(1);
}
*/

/*
template <typename T>
void foo(const T& t) {
	std::cout << "template " << t << "\n";
}

void foo(const int& i) { std::cout << "unsigned " << i << "\n"; }

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
process(T value) {
    std::cout << "Processing integer: " << value << std::endl;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type process(T value) {
    std::cout << "Processing floating point: " << value << std::endl;
}

int	main(void)
{
	int a;
	foo(42);
	process(42);
	process(42.0f);
	return 0;
}
*/