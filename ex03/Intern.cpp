#include "Intern.hpp"

Intern::Intern(void)
{
} 

Intern::Intern(Intern const &other) 
{
	(void) other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void) other;
	return (*this);
}

Intern::~Intern()
{
}

AForm	*Intern::makePres(std::string const &target)
{
	AForm	*save;

	save = new PresidentialPardonForm(target);
	return (save);
}

AForm	*Intern::makeShrub(std::string const &target)
{
	AForm	*save;

	save = new ShrubberyCreationForm(target);
	return (save);
}

AForm	*Intern::makeRobot(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(std::string const &form_name, std::string target)
{
	std::string	const forms[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	AForm	*(Intern::*tab[])(std::string const &) = {&Intern::makePres, &Intern::makeShrub, &Intern::makeRobot};
	int	i = 0;
	AForm	*exit = NULL;

	while (i < 3)
	{
		if (form_name == forms[i])
		{
			exit = (this->*tab[i])(target);
			break;
		}
		i++;
	}
	if (i == 3)
	{
		throw InvalidFormName();
	}
	std::cout << "Intern succesfully created " << forms[i] << std::endl;
	return (exit);
}
