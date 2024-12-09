#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Creating 4 bureaucrats with next grades: 1, 150, -42, 442" << std::endl;
    std::cout << "======================" << std::endl;
    Bureaucrat bureaucrat1("John", 1);  // Valid
    std::cout << bureaucrat1 << std::endl;
    Bureaucrat bureaucrat2("Calin", 150);  // Valid
    std::cout << bureaucrat2 << std::endl;
    std::cout << "============== INVALID ============" << std::endl;
    try
    {
        Bureaucrat bureaucrat3("Marius", -42);  // Invalid grade
        std::cout << bureaucrat3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception for Marius: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat4("Mihai", 442);  // Invalid grade
        std::cout << bureaucrat4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception for Mihai: " << e.what() << std::endl;
    }
    std::cout << "============== INVALID incr and decr ======" << std::endl;
    try
    {
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade(); // Incrementing
    }
    catch (std::exception &e)
    {
        std::cout << "Exception increment: " << e.what() << std::endl;
    }
    try
    {
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade(); // Decrementing
    }
    catch (std::exception &e)
    {
        std::cout << "Exception decrement: " << e.what() << std::endl;
    }
    return 0;
}