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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}