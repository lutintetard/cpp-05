#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 

# include <string>
# include <iostream>
# include <exception>
# include <ostream>
# include "Form.hpp"

class Bureaucrat
{
private:
	std::string const name;
	int	grade;
public:
	Bureaucrat(std::string const &name, int const &value);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat(void);
	std::string const &getName()const;
	int	getGrade() const;
	void	increase_clearence();
	void	decrease_clearence();
	void	signForm(Form &form);
	class GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw()
		{
			return "Grade is too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw()
		{
			return "Grade is too low";
		}
	};
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &person);

#endif
