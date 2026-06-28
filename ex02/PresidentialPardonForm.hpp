#ifndef PRESDIENTIALPARDONFORM_HPP
# define PRESDIENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class	PresidentialPardonForm : public AForm
{
private:
	std::string const	target;
public:
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif
