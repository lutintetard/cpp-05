#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : 
AForm::AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : 
AForm(other.getName(), other.getSign(), other.getExec()), target(target)
{
	if (other.getStatus())
		this->setStatus(true);
	else
		this->setStatus(false);	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this == &other)
		return (*this);
	if (other.getStatus())
		this->setStatus(true);
	else
		this->setStatus(false);	
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	file_name;
	file_name = "tree -al >" + this->target + "_shruberry";
	try
	{
		this->execFile(executor);
	}
	catch (std::exception &e)
	{
		std::cout << "The Bureaucrat could not execute this form because: ";
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::system(file_name.c_str());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
}
