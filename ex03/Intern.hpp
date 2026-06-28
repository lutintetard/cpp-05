#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <exception>

class	AForm;

class	Intern
{
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();
	AForm *makeForm(std::string form_name, std::string target);
	class	InvalidFormName : std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "form name does not correspond to anything";
		}
	};
};

#endif
