#include <iostream>
#include "Span.hpp"
#include <deque>

int main()
{
	try
	{
	std::cout << "\n     --case 1--\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.addNumber(15);
	return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	std::cout << "\n     --case 2--\n";
	Span sp = Span(5);
	std::deque<int>	dequeInt;


	dequeInt.push_front(5);
	dequeInt.push_front(6);
	dequeInt.push_front(7);
	dequeInt.push_front(8);
	dequeInt.push_front(1);

	sp.fill(dequeInt.begin(), dequeInt.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.fill(dequeInt.begin(), dequeInt.end());
	return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	std::cout << "\n     --case 3--\n";
	Span sp = Span(5);
	std::set<int>	setInt;


	setInt.insert(2);
	setInt.insert(4);
	setInt.insert(6);
	setInt.insert(10);
	setInt.insert(50);

	sp.fill(setInt.begin(), setInt.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.fill(setInt.begin(), setInt.end());
	return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	std::cout << "\n     --case 4--\n";
	Span sp = Span(5);

	std::cout << sp.shortestSpan() << std::endl;
	return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	std::cout << "\n     --case 5--\n";
	Span sp = Span(5);

	sp.addNumber(1);
	std::cout << sp.longestSpan() << std::endl;
	return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
