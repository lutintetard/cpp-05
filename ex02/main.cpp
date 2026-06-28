#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	PresidentialPardonForm	form("target");
	Bureaucrat				peter("peter", 1);

	peter.signForm(form);
	form.execute(peter);
	return 0;
}
