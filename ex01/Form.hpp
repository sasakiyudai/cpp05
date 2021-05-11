#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
class Form;
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const name;
		bool isSigned;
		int const signGrade;
		int const execGrade;
		Form();
	public:
		Form(std::string const &name, int const signGarde, int const execGrade);
		Form(Form const &other);
		virtual ~Form();
		Form &operator=(Form const &other);

		std::string const &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		void beSigned(Bureaucrat const bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
