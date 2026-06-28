#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class	ShruberryCreationForm : public AForm
{
private:
	std::string const	target;
public:
	ShruberryCreationForm(std::string const target);
	ShruberryCreationForm(ShruberryCreationForm const &other);
	ShruberryCreationForm &operator=(ShruberryCreationForm const &other);
	~ShruberryCreationForm();
	void	execute(Bureaucrat const &executor);	
}

#endif
