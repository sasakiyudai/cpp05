#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	Bureaucrat gendo("gendo", 1);
	Bureaucrat misato("misato", 1);
	Bureaucrat shinji("shinji", 150);
	Bureaucrat rei("rei", 10);
	Bureaucrat kuronami("kuronami", 10);
	Bureaucrat asuka("asuka", 11);

	std::cout << gendo << std::endl;
	std::cout << misato << std::endl;
	std::cout << shinji << std::endl;
	std::cout << rei << std::endl;
	std::cout << kuronami << std::endl;
	std::cout << asuka << std::endl;

	ShrubberyCreationForm VILE_project("brack_moon");
	ShrubberyCreationForm NERV_project("white_moon");
	RobotomyRequestForm Robotomy1("asuka");
	RobotomyRequestForm Robotomy2("rei");
	PresidentialPardonForm Presidential1("shinji");
	PresidentialPardonForm Presidential2("kaworu");

	try
	{
		gendo.signForm(VILE_project);
		gendo.executeForm(VILE_project);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		misato.executeForm(NERV_project);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		shinji.signForm(NERV_project);
		shinji.executeForm(NERV_project);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		misato.signForm(NERV_project);
		shinji.executeForm(NERV_project);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		asuka.executeForm(Robotomy1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		rei.signForm(Robotomy2);
		asuka.executeForm(Robotomy2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		asuka.executeForm(Robotomy2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		gendo.signForm(Presidential1);
		gendo.executeForm(Presidential1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		misato.executeForm(Presidential2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		misato.signForm(Presidential2);
		misato.executeForm(Presidential2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}