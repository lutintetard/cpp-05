#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include <iostream>
# include <exception>

class	AForm;

class	Intern
{
private:
	AForm	*makePres(std::string const &target);
	AForm	*makeShrub(std::string const &target);
	AForm	*makeRobot(std::string const &target);
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();
	AForm *makeForm(std::string const &form_name, std::string target);
	class	InvalidFormName : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "form name does not correspond to anything";
		}
	};
};

#endif
