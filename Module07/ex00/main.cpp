#include "whatever.hpp"

int	main(void)
{
	int intA = 10;
	int intB = 20;
	std::cout << "bf swap : intA = " << intA << ", intB = " << intB << '\n';
	int	minInt = min(intA, intB);
	int	maxInt = max(intA, intB);
	swap(intA, intB);
	std::cout << "af swap : intA = " << intA << ", intB = " << intB << ", min = " << minInt << ", max = " << maxInt << '\n';
	intB = 20;
	std::cout << "same case : min = " << min(intA, intB) << ", max = " << max(intA, intB) << '\n';

	std::cout << '\n' << '\n';

	const int constintA = 10;
	const int constintB = 20;
	std::cout << "bf swap : constintA = " << constintA << ", constintB = " << constintB << '\n';
	const int	constminInt = min(constintA, constintB);
	const int	constmaxInt = max(constintA, constintB);
	swap(constintA, constintB);
	std::cout << "af swap : constintA = " << constintA << ", constintB = " << constintB << ", min = " << constminInt << ", max = " << constmaxInt << '\n';
	// constintB = 20;
	std::cout << "same case : min = " << min(constintA, constintB) << ", max = " << max(constintA, constintB) << '\n';

	std::cout << '\n' << '\n';

	double doubleA = 20.4;
	double doubleB = 20.6;
	std::cout << "bf swap : doubleA = " << doubleA << ", doubleB = " << doubleB << '\n';
	double	minDouble = min(doubleA, doubleB);
	double	maxDouble = max(doubleA, doubleB);
	swap(doubleA, doubleB);
	std::cout << "af swap : doubleA = " << doubleA << ", doubleB = " << doubleB << ", min = " << minDouble << ", max = " << maxDouble << '\n';
	doubleB = 20.6;
	std::cout << "same case : min = " << min(doubleA, doubleB) << ", max = " << max(doubleA, doubleB) << '\n';
	
	std::cout << '\n' << '\n';

	const char*	charPtrA = "test1";
	const char*	charPtrB = "test2";
	std::cout << "bf swap : charPtrA = " << charPtrA << ", charPtrB = " << charPtrB << '\n';
	const char*	mincharPtr = min(charPtrA, charPtrB);
	const char*	maxcharPtr = max(charPtrA, charPtrB);
	swap(charPtrA, charPtrB);
	std::cout << "af swap : charPtrA = " << charPtrA << ", charPtrB = " << charPtrB << ", min = " << mincharPtr << ", max = " << maxcharPtr << '\n';
	charPtrB = "test2";
	std::cout << "same case : min = " << min(charPtrA, charPtrB) << ", max = " << max(charPtrA, charPtrB) << '\n';
	
	std::cout << '\n' << '\n';

	std::string	stringA = "dongyeuk";
	std::string	stringB = "sungyoon";
	std::cout << "bf swap : stringA = " << stringA << ", stringB = " << stringB << '\n';
	// double	minDouble = min(stringA, stringB);
	// double	maxDouble = max(stringA, stringB);
	swap(stringA, stringB);
	// stringA.swap(stringB);
	std::cout << "af swap : stringA = " << stringA << ", stringB = " << stringB << '\n';
	// std::cout << "af swap : stringA = " << stringA << ", stringB = " << stringB << ", min = " << minDouble << ", max = " << maxDouble << '\n';
	// stringB = "sungyoon";
	// std::cout << "same case : min = " << min(stringA, stringB) << ", max = " << max(stringA, stringB) << '\n';
}
