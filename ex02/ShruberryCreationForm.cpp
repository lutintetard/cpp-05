#include "ShruberryCreationForm.cpp"

ShruberryCreationForm::ShruberryCreationForm(std::string const target) : 
AForm("ShruberryCreationForm", 25, 5), target(target)
{
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const &other)
{
	this->other.getStatus();
}

ShruberryCreationForm &ShruberryCreationForm::operator=(ShruberryCreationForm const &other)
{
	if (this == &other)
		return (*this);
	this->other.getStatus;
}

ShruberryCreationForm::~ShruberryCreationForm() : ~AForm()
{

}

bool	ShruberryCreationForm::execute(Bureaucrat const &executor) const
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
