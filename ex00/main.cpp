#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat *save_bro_1 = NULL;
	Bureaucrat *save_bro_2 = NULL;
	Bureaucrat *save_bro_3 = NULL;
	Bureaucrat *save_bro_4 = NULL;
	Bureaucrat *save_bro_5 = NULL;

	try
	{
		save_bro_1 = new Bureaucrat("john", 55);
		save_bro_2 = new Bureaucrat("clara", 1);
		save_bro_3 = new Bureaucrat("jean", 150);
		save_bro_4 = new Bureaucrat("alice", -99);
		save_bro_5 = new Bureaucrat("samy", 153);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		save_bro_1->increase_clearence();
		save_bro_3->decrease_clearence();
		save_bro_2->increase_clearence();
	}
	catch (std::exception &code)
	{
		std::cout << code.what() << std::endl;
	}
	std::cout << *save_bro_1 << std::endl;
	std::cout << *save_bro_2 << std::endl;
	std::cout << *save_bro_3 << std::endl;
	std::cout << "end of program" << std::endl;
	(void) save_bro_4;
	(void) save_bro_5;
	delete (save_bro_1);
	delete (save_bro_2);
	delete (save_bro_3);
	return (0);
}
