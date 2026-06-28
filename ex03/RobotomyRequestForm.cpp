#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : 
AForm::AForm("RobotomyRequestForm", 25, 5, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : 
AForm(other.getName(), other.getSign(), other.getExec(), target.getTarget())
{
	if (other.getStatus())
		this->setStatus(true);
	else
		this->setStatus(false);	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this == &other)
		return (*this);
	if (other.getStatus())
		this->setStatus(true);
	else
		this->setStatus(false);	
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
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
	if (rand() % 2 == 0)
		std::cout << "Robotomy on " << this->getTarget() << " saddly failed :)" << std::endl;
	else
		std::cout << "Robotomy on " << this->target << " saddly succeeded :(" << std::endl;
}
