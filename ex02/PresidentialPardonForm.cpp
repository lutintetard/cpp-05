#include "PresidentialPardonForm.cpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : 
AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
{
	this->other.getStatus();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this == &other)
		return (*this);
	this->other.getStatus;
}

PresidentialPardonForm::~PresidentialPardonForm() : ~AForm()
{

}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->execFile();
	}
	catch (std::exception &e)
	{
		std::cout << "The Bureaucrat could not execute this form because: ";
		std::cout << e.what() << std::endl;
		return (false);
	}
	std::cout << this->target << " has received a presidential pardon" << std::endl;
	return (true);
}
