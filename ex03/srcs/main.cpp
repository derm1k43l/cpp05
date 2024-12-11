#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat b1("Mihai Boss", 1);
    std::cout << b1 << std::endl;
    Bureaucrat b2("John pielea", 142);
    std::cout << b2 << std::endl;
    Bureaucrat b3("Ben middle management", 70);
    std::cout << b3 << std::endl;
    try
    {
        Bureaucrat slaker1("Slaker1", 666);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Intern intern;

    AForm* form1 = intern.makeForm("ShrubberyCreationForm", "whatever");
    b1.signForm(*form1);
    b1.executeForm(*form1);
    std::cout << *form1 << std::endl;

    AForm* form2 = intern.makeForm("PresidentialPardonForm", "Sednaya Prison inmate");
    AForm* form3 = intern.makeForm("RobotomyRequestForm", "Bender");
    try
    {
        AForm* form4 = intern.makeForm("NonExistentForm", "whatever");
        if (form4 == nullptr)
            std::cout << "Form4 is nullptr" << std::endl;
        else
            std::cout << *form4 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        b2.signForm(*form2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        b2.signForm(*form3);
        b2.executeForm(*form3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        b3.signForm(*form3);
        b3.executeForm(*form3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    b1.signForm(*form2);
    b2.executeForm(*form2);
    b1.executeForm(*form2);
    b1.signForm(*form3);
    b1.executeForm(*form3);

    delete form1;
    delete form2;
    delete form3;
    return 0;    
}