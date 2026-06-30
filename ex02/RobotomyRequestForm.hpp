#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <ctime>

class Bureaucrat;

class	RobotomyRequestForm : public AForm
{
private:
	std::string const	target;
public:
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif
