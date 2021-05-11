#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name),grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	grade = other.grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->name);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low!";
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incGrade()
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade()
{
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) const
{
	if (form.getIsSigned() || form.getSignGrade() < this->grade)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because ";
		if (form.getIsSigned())
			std::cout << "this form is already signed." << std::endl;
		else
			std::cout << "his grade is low." << std::endl;
	}
	else
	{
		std::cout << this->name << " signs " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

void Bureaucrat::executeForm(Form const &form) const
{
	if (form.getIsSigned() == false || form.getExecGrade() < this->grade)
	{
		std::cout << this->name << " cannot execute " << form.getName() << " because ";
		if (form.getIsSigned() == false)
			std::cout << "this form is not signed." << std::endl;
		else
			std::cout << "his grade is low." << std::endl;
	}
	else
	{
		std::cout << this->name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}