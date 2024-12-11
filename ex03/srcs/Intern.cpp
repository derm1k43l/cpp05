#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const& other)
{
    (void)other;
}

Intern& Intern::operator=(Intern const& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

//member functions
AForm* Intern::createShrubberyForm(std::string const& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialForm(std::string const& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyForm(std::string const& target)
{
    return new RobotomyRequestForm(target);
}

// main makeForm function using the above helper functions
AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
    std::map<std::string, AForm*(Intern::*)(std::string const&)> formMap = 
    {
        {"ShrubberyCreationForm", &Intern::createShrubberyForm},
        {"PresidentialPardonForm", &Intern::createPresidentialForm},
        {"RobotomyRequestForm", &Intern::createRobotomyForm}
    };

    // search for the form name in the map
    auto it = formMap.find(formName);
    if (it != formMap.end())
    {
        // if found, call the corresponding helper function
        return (this->*(it->second))(target);
    }
    else
    {
        // if not found, return nullptr
        std::cout << "Form " << formName << " not found." << std::endl;
        return nullptr;
    }
}
