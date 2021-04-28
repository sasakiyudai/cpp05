#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM
#define TREE_COUNT 5

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm: public Form
{
	private:
		std::string target;
		static std::string trees;
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		
		void execute(Bureaucrat const &executor) const;
		class CantOpenFileException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
