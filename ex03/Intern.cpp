#include "Intern.hpp"

Intern::Intern(void)
{
} 

Inter::Intern(Intern const &other)
{
}

Inter &operator=Intern(Intern const &other)
{
}

Intern::~Intern()
{
}
 
AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string	forms[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	AForm	*(*tab[]()) = {&PresidentialPardonForm, &ShrubberyCreationForm, &RobotomyRequestForm};
	int	i = 0;
	AForm	*exit;

	while (i < 3)
	{
		if (form_name == forms[i])
			exit = new tab[i](target);
		i++;
	}
	if (i == 3)
	{
		throw InvalidFormName();
	}
	return (exit);
}
