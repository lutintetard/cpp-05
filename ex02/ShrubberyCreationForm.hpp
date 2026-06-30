#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <sstream>

class Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
private:
	std::string const	target;
public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif
