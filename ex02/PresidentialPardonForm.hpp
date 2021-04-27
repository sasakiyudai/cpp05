#ifndef PRESIDENTIALPARDON_FORM
#define PRESIDENTIALPARDON_FORM

#include "Form.hpp"
#include <string>

class PresidentialPardonForm: public Form
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		
		void execute(Bureaucrat const &executor) const;
};

#endif
