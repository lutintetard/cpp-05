#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    // Création de quelques bureaucrates
    Bureaucrat boss("Zaphod", 1);
    Bureaucrat intern("Bob", 150);
    Bureaucrat mid("Manager", 50);

    // Test des formulaires
    ShrubberyCreationForm f1("Garden");
    RobotomyRequestForm f2("Wall-E");
    PresidentialPardonForm f3("Arthur Dent");

    std::cout << "--- Test 1: Intern essaie de signer (doit échouer) ---" << std::endl;
    intern.signForm(f1);

    std::cout << "\n--- Test 2: Boss signe et exécute Shrubbery ---" << std::endl;
    boss.signForm(f1);
    boss.executeForm(f1);

    std::cout << "\n--- Test 3: Robotomy (50% de chance) ---" << std::endl;
    boss.signForm(f2);
    boss.executeForm(f2);
    boss.executeForm(f2);

    std::cout << "\n--- Test 4: Presidential Pardon ---" << std::endl;
    mid.signForm(f3); // Manager peut signer (grade 50 < 25 ? Non, échoue)
    boss.signForm(f3);
    boss.executeForm(f3);

    std::cout << "\n--- Test 5: Tester exécution sans signature ---" << std::endl;
    RobotomyRequestForm f4("Terminator");
    try {
        boss.executeForm(f4);
    } catch (std::exception &e) {
        std::cerr << "Exception capturée: " << e.what() << std::endl;
    }

    return 0;
}
