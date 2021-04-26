#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat gendo("gendo", 1);
	Bureaucrat misato("misato", 1);
	Bureaucrat shinji("shinji", 150);
	Bureaucrat rei("rei", 10);
	Bureaucrat kuronami("kuronami", 10);
	Bureaucrat asuka("asuka", 11);

	std::cout << gendo << std::endl;
	std::cout << misato << std::endl;
	std::cout << shinji << std::endl;
	std::cout << rei << std::endl;
	std::cout << kuronami << std::endl;
	std::cout << asuka << std::endl;

	Form HOKAN_KEIKAKU("HOKAN_KEIKAKU", 1, 1);
	Form ZINRUI_HOKAN_KEIKAKU("ZINRUI_HOKAN_KEIKAKU", 1, 1);
	Form VUNDAR("VUNDAR", 10, 10);
	Form ONE_EVA("ONE_EVA", 10, 10);
	Form EVA("EVA", 10, 10);

	std::cout << HOKAN_KEIKAKU << std::endl;
	std::cout << ZINRUI_HOKAN_KEIKAKU << std::endl;
	std::cout << VUNDAR << std::endl;
	std::cout << ONE_EVA << std::endl;

	try
	{
		gendo.signForm(HOKAN_KEIKAKU);
		std::cout << gendo << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		misato.decGrade();
		std::cout << misato << std::endl;
		misato.signForm(ZINRUI_HOKAN_KEIKAKU);
		std::cout << misato << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		shinji.signForm(VUNDAR);
		std::cout << shinji << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		misato.signForm(VUNDAR);
		std::cout << misato << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		rei.signForm(EVA);
		std::cout << rei << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		kuronami.signForm(EVA);
		std::cout << kuronami << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		asuka.signForm(ONE_EVA);
		std::cout << asuka << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		shinji.decGrade();
	}
	catch(const std::exception &e)
	{

	}
	std::cout << shinji << std::endl;
	Form tmp("tmp", 5, 5);
	try
	{
		tmp.beSigned(shinji);
		std::cout << shinji << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << HOKAN_KEIKAKU << std::endl;
	std::cout << ZINRUI_HOKAN_KEIKAKU << std::endl;
	std::cout << VUNDAR << std::endl;
	std::cout << ONE_EVA << std::endl;
}