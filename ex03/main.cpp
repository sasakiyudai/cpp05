#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	Bureaucrat gendo("gendo", 1);
	Intern ayanami;

	Form *tmp;
	tmp = ayanami.makeForm("presidential pardon", "shinji");
	if (tmp)
	{
		gendo.signForm(*tmp);
		gendo.executeForm(*tmp);
		delete tmp;
	}
	tmp = ayanami.makeForm("robotomy request", "asuka");
	if (tmp)
	{
		gendo.signForm(*tmp);
		gendo.executeForm(*tmp);
		delete tmp;
	}
	tmp = ayanami.makeForm("shrubbery creation", "daisanmura");
	if (tmp)
	{
		gendo.signForm(*tmp);
		gendo.executeForm(*tmp);
		delete tmp;
	}
	tmp = ayanami.makeForm("ZINRUI-HOKAN-KEIKAKU", "yui");
	if (tmp)
	{
		gendo.signForm(*tmp);
		gendo.executeForm(*tmp);
		delete tmp;
	}
}