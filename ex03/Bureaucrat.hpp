#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &other);

		std::string const &getName() const;
		int getGrade() const;
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
		void incGrade();
		void decGrade();
		void signForm(Form &form) const;
		void executeForm(Form const &form) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
