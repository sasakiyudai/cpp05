#ifndef INTERN_HPP
#define INTERN_HPP
#define FORM_COUNT 3

#include <string>
#include <exception>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		virtual ~Intern();
		Intern &operator=(Intern const &other);

		Form *makeForm(std::string const &form, std::string const &target);
};

#endif
