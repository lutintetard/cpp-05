#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== TEST 1 : Création de formulaires valides et invalides ===" << std::endl;
    try {
        Form f1("Contrat de travail", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTentative de création d'un formulaire avec un grade trop haut (0) :" << std::endl;
        Form f_high("Top Secret", 0, 50);
    } catch (std::exception &e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTentative de création d'un formulaire avec un grade trop bas (151) :" << std::endl;
        Form f_low("Formulaire inutile", 151, 150);
    } catch (std::exception &e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "=== TEST 2 : Signature réussie ===" << std::endl;
    try {
        Bureaucrat boss("Hermes", 10);
        Form taxForm("Feuille d'impôts", 45, 30);

        std::cout << boss << std::endl;
        std::cout << taxForm << std::endl;

        // Le bureaucrat tente de signer (grade 10 >= grade requis 45)
        boss.signForm(taxForm);

        std::cout << "\nÉtat du formulaire après tentative :" << std::endl;
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "=== TEST 3 : Échec de signature (Grade trop bas) ===" << std::endl;
    try {
        Bureaucrat intern("Stagiaire", 140);
        Form NDA("Accord de Confidentialité", 20, 10);

        std::cout << intern << std::endl;
        std::cout << NDA << std::endl;

        // Le stagiaire tente de signer (grade 140 < grade requis 20)
        intern.signForm(NDA);

        std::cout << "\nÉtat du formulaire après tentative :" << std::endl;
        std::cout << NDA << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception inattendue : " << e.what() << std::endl;
    }

    return 0;
}
