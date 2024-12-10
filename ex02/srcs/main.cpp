#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat b1("Mihai Boss ", 1);
    Bureaucrat b2("John pielea", 142);

    ShrubberyCreationForm f1("Form1");
    RobotomyRequestForm f2("Form2");
    PresidentialPardonForm f3("Form3");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    try 
    {
        b1.signForm(f2);
        b1.signForm(f3);
    }
    catch (std::exception &e) {std::cerr << e.what() << std::endl;}

    try
    {
        b2.signForm(f2);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        b2.signForm(f1);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        b2.signForm(f3);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        b1.signForm(f2);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        b1.signForm(f3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
    return 0;
}

