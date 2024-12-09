#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        //create bureaucrats
        Bureaucrat b1("Bureaucrat1", 1);
        Bureaucrat b2("Bureaucrat2", 142);
        //create forms
        Form fa("Form1", 1, 1);
        Form fb("Form2", 142, 142);
        // print forms status
        std::cout << fa << std::endl;
        std::cout << fb << std::endl;
        // sign forms
        b1.signForm(fa);
        std::cout << fa << std::endl;
        b2.signForm(fb);
        std::cout << fb << std::endl;
        b1.signForm(fb);
        std::cout << fb << std::endl;
        // double sign exception
        try
        {
            b1.signForm(fb);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}