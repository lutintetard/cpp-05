#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <ostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const &_name;
	bool	_signed;
	int const	_min_to_sign;
	int const	_min_to_exec;
public:
	Form(std::string const &name, int const sign, int const exec);
	Form(Form const &other);
	Form &operator=(Form const &other);	
	~Form(void);
	std::string const &getName() const;
	bool	getStatus() const;
	int	getSign() const;
	int	getExec() const;
	void	beSigned(Bureaucrat const &other);
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "the grade level is too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "the grade level is too low";
		}
	};
};

std::ostream &operator<<(std::ostream &stream, Form const &form);

#endif
