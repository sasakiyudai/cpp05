#include "Intern.hpp"
#include <utility>

static Form *makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static Form *makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static Form *makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern()
{
	
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Form *Intern::makeForm(std::string const &form, std::string const &target)
{
	Form *ret = NULL;
	typedef Form* (*func_t)(std::string const &target);
	std::string forms_name[FORM_COUNT] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	func_t forms_func[FORM_COUNT] = {makePresidentialPardonForm, makeRobotomyRequestForm, makeShrubberyCreationForm};

	for (int i = 0; i < FORM_COUNT; i++)
	{
		if (forms_name[i] == form)
		{
			ret = forms_func[i](target);
			std::cout << "Intern creates " << ret->getName() << std::endl;
			return (ret);
		}
	}
	std::cout << "There is no " << form << std::endl;
	return (ret);
}
