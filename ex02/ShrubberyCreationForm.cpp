#include "ShrubberyCreationForm.hpp"
#include <fstream>

std::string ShrubberyCreationForm::trees = 
	"       /8      \n"
	"      /888     \n"
	"     /88888    \n"
	"    /8888888   \n"
	"   /888888888  \n"
	"  /88888888899 \n"
	" /8888888889999\n"
	"       ||      \n"
	"       ||      \n"
	"       ||      \n";

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):Form("Shurubbery Creation", 145, 137),target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):Form("Shurubbery Creation", 145, 137),target(other.target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	target = other.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::string filename(target + "_shrubbery");
	std::ofstream outputfile(filename, std::ios::app);

	if (outputfile)
	{
		for (int i = 0; i < TREE_COUNT; i++)
			outputfile << ShrubberyCreationForm::trees;
	}
	else
		throw CantOpenFileException();
	outputfile << std::endl;
}

const char* ShrubberyCreationForm::CantOpenFileException::what() const throw()
{
	return "can't open the file!";
}
