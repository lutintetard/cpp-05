#include "Form.hpp"

Form::Form(std::string const name, int const sign, int const exec):
_name(name), _min_to_sign(sign), _min_to_exec(exec)
{
	if (sign < 1)
		throw (GradeTooHighException());
	if (sign > 150)
		throw (GradeTooLowException());
	this->_signed = false;
}

Form::Form(Form const &other) : _name(other._name), 
_min_to_sign(other._min_to_sign), _min_to_exec(other._min_to_exec)
{
	this->_signed = false;	
}

Form &Form::operator=(Form const &other)
{
	if (this == &other)
		return *this;
	this->_signed = other.getStatus();
	return *this;
}

Form::~Form(void)
{
}

std::string const &Form::getName() const
{
	return (this->_name);
}

bool	Form::getStatus() const
{
	return (_signed);
}

int	Form::getSign() const
{
	return (_min_to_sign);
}

int	Form::getExec() const
{
	return (_min_to_exec);
}

void	Form::beSigned(Bureaucrat const &other)
{
	if (other.getGrade() > this->_min_to_sign)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &stream, Form const &form)
{
	stream << "form : ";
	stream << form.getName();
	stream << " signed status: ";
	stream << form.getStatus();
	stream << " min level to sign: ";
	stream << form.getSign();
	stream << " min level to exec: ";
	stream << form.getExec();
	return (stream);
}
