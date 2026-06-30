#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int const &value) :
name(name), grade(value)
{
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();

	std::cout << "Bureaucrat created succesfully" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->name << " has been deleted" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return (name);
}

int		Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << "." << std::endl;
		return ;
	}
	std::cout << name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::increase_clearence()
{
	if (grade == 1)
		throw (GradeTooHighException()); 
	grade--;
}

void	Bureaucrat::decrease_clearence()
{
	if (grade == 150)
		throw (GradeTooLowException()); 
	grade++;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execFile(*this);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}
	form.execute(*this);
	std::cout << this->getName() << " has succesfully executed the form" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &person)
{
	stream << person.getName();
	stream << ", bureaucrat grade ";
	stream << person.getGrade();
	stream << ".";
	return (stream);
}
