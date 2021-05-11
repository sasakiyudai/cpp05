#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm():Form()
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):Form("robotomy request", 72, 45),target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):Form("robotomy request", 72, 45),target(other.target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	target = other.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "GAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGA" << std::endl;

	int fifty_fifty = std::rand() % 2;
	if (fifty_fifty == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " has NOT been robotomized" << std::endl;
}
