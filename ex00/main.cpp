#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat suga("suga", 1);
	Bureaucrat abe("abe", 1);
	Bureaucrat asou("asou", 2);
	Bureaucrat seikin("seikin", 150);
	Bureaucrat hikakin("hikakin", 149);

	std::cout << suga << std::endl;
	std::cout << abe << std::endl;
	std::cout << asou << std::endl;
	std::cout << seikin << std::endl;
	std::cout << hikakin << std::endl;

	try
	{
		suga.incGrade();
		std::cout << suga << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		abe.decGrade();
		std::cout << abe << std::endl;
		abe.decGrade();
		std::cout << abe << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		asou.decGrade();
		std::cout << asou << std::endl;
		asou.decGrade();
		std::cout << asou << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		seikin.decGrade();
		std::cout << seikin << std::endl;
		seikin.decGrade();
		std::cout << seikin << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		hikakin.decGrade();
		std::cout << hikakin << std::endl;
		hikakin.decGrade();
		std::cout << hikakin << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}