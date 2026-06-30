#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <ostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool	_signed;
	int const	_min_to_sign;
	int const	_min_to_exec;
public:
	AForm(std::string const name, int const sign, int const exec);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	~AForm(void);
	std::string const &getName() const;
	bool	getStatus() const;
	int	getSign() const;
	int	getExec() const;
	void	setStatus(bool val);
	void	beSigned(Bureaucrat const &other);
	void	execFile(Bureaucrat const &other) const;
	virtual void	execute(Bureaucrat const &executor) const = 0;
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
	class AlreadySigned : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "this form has already been signed";
		}
	};
	class NotSigned : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "this form has not been signed";
		}
	};
};

std::ostream &operator<<(std::ostream &stream, AForm const &form);

#endif
