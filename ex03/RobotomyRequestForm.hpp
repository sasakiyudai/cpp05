#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "Form.hpp"
#include <string>

class RobotomyRequestForm: public Form
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		
		void execute(Bureaucrat const &executor) const;
};

#endif
