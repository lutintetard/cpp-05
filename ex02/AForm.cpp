#include "AForm.hpp"

AForm::AForm(std::string const name, int const sign, int const exec):
_name(name), _min_to_sign(sign), _min_to_exec(exec)
{
	if (sign < 1)
		throw (GradeTooHighException());
	if (sign > 150)
		throw (GradeTooLowException());
	this->_signed = false;
}

AForm::AForm(AForm const &other) : _name(other._name), 
_min_to_sign(other._min_to_sign), _min_to_exec(other._min_to_exec)
{
	this->_signed = false;
}

AForm &AForm::operator=(AForm const &other)
{
	if (this == &other)
		return *this;
	this->_signed = other.getStatus();
	return *this;
}

AForm::~AForm(void)
{
}

std::string const &AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getStatus() const
{
	return (_signed);
}

int	AForm::getSign() const
{
	return (_min_to_sign);
}

int	AForm::getExec() const
{
	return (_min_to_exec);
}

void	AForm::setStatus(bool val)
{
	this->_signed = val;
}

void	AForm::beSigned(Bureaucrat const &other)
{
	if (other.getGrade() > this->_min_to_sign)
		throw GradeTooLowException();
	if (this->_signed == true)
		throw AlreadySigned();
	this->_signed = true;
}

void	AForm::execFile(Bureaucrat const &other) const
{
	if (other.getGrade() > this->_min_to_sign)
		throw GradeTooLowException();
	if (this->getStatus() == false)
		throw NotSigned();
}

std::ostream	&operator<<(std::ostream &stream, AForm const &form)
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
