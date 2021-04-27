#include "Form.hpp"

Form::Form(std::string const &name, int const signGrade, int const execGrade):name(name),isSigned(false),signGrade(signGrade),execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooLowException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &other):name(other.name),isSigned(other.isSigned),signGrade(other.signGrade),execGrade(other.execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooLowException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooHighException();
}

Form::~Form()
{

}

Form &Form::operator=(Form const &other)
{
	isSigned = other.isSigned;
	return (*this);
}

std::string const &Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecGrade() const
{
	return (this->execGrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low!";
}

void Form::beSigned(Bureaucrat const bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", signable grade " << form.getSignGrade() << " executable grade " << form.getExecGrade() << " and this is ";
	if (form.getIsSigned() == false)
		out << "not ";
	out << "signed so far.";
	return (out);
}
