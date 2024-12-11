#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <map>
#include <iostream>

class Intern
{
    public: 
        Intern();
        Intern(Intern const& other);
        Intern& operator=(Intern const& other);
        ~Intern();

        AForm* makeForm(std::string const& formName, std::string const& target);
    private:
        AForm* createShrubberyForm(std::string const& target);
        AForm* createPresidentialForm(std::string const& target);
        AForm* createRobotomyForm(std::string const& target);
};