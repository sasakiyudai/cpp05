#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():Form()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):Form("presidential pardon", 25, 5),target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):Form("presidential pardon", 25, 5),target(other.target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	target = other.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
