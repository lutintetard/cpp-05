#ifndef PRESDIENTIALPARDONFORM_HPP
# define PRESDIENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	std::string const	target;
	bool	action_form();	
public:
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
}

#endif
