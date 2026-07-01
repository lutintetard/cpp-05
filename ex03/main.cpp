#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Petite fonction utilitaire pour afficher les titres des sections de tests
void printTitle(const std::string& title) {
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

int main() {
    Intern someRandomIntern;
    AForm* rrf = NULL;

    // ==========================================
    // TEST 1 : Robotomy Request (Le cas du sujet)
    // ==========================================
    printTitle("Test 1: Creation d'un Robotomy Request");
    
	try
	{
    	rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	}	
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}
	if (rrf != NULL)
    {
		std::cout << "Verification du type cree : " << rrf->getName() << std::endl;
    	std::cout << "Target du formulaire : " << rrf->getTarget() << std::endl;
    	delete rrf; // Toujours delete pour eviter les leaks !
    	rrf = NULL;
	}
   

    // ==========================================
    // TEST 2 : Shrubbery Creation
    // ==========================================
    printTitle("Test 2: Creation d'un Shrubbery Creation");
    try
	{
    	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Zaphod Beeblebrox");
	}	
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}
    if (rrf != NULL) {
        std::cout << "Verification du type cree : " << rrf->getName() << std::endl;
        delete rrf;
        rrf = NULL;
    }

    // ==========================================
    // TEST 3 : Presidential Pardon
    // ==========================================
    printTitle("Test 3: Creation d'un Presidential Pardon");
    try
	{
    	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Zaphod Beeblebrox");
	}	
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}
    if (rrf != NULL) {
        std::cout << "Verification du type cree : " << rrf->getName() << std::endl;
        delete rrf;
        rrf = NULL;
    }

    // ==========================================
    // TEST 4 : Formulaire Inconnu (Cas d'erreur)
    // ==========================================
    printTitle("Test 4: Tentative avec un faux formulaire (Doit echouer)");
    
    // L'intern doit afficher un message d'erreur explicite et renvoyer NULL
    try
	{
    	rrf = someRandomIntern.makeForm("presidential pardon", "Zaphod Beeblebrox");
	}	
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}    
	if (rrf == NULL)
	{
        std::cout << "Succes du test : L'intern a bien renvoye un pointeur NULL." << std::endl;
    }    
	printTitle("FIN DES TESTS");
    return 0;
}
