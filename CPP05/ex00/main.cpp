#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("Bob", 120);
		std::cout << test;
		test.grade_increment();
		test.grade_increment();
		std::cout << test;
		test.grade_decrement();
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "-----------------------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat test("Jack", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "-----------------------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat test("Pat", 150);
		std::cout << test;
		test.grade_decrement();
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "-----------------------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat test("Mat", 1);
		std::cout << test;
		test.grade_increment();
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}