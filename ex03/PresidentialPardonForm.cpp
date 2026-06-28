#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : 
AForm::AForm("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : 
AForm::AForm(other.getName(), other.getSign(), other.getExec(), other.getTarget())
{
	if (other.getStatus())
		this->setStatus(true);
	else
		this->setStatus(false);	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this == &other)
		return (*this);
	if (other.getStatus())
		this->setStatus(true);
	else
		this->setStatus(false);	
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->execFile(executor);
	}
	catch (std::exception &e)
	{
		std::cout << "The Bureaucrat could not execute this form because: ";
		std::cout << e.what() << std::endl;
	}
	std::cout << this->getTarget() << " has received a presidential pardon" << std::endl;
}
