#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target_(other.target_)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::performAction() const
{
    //create file 
    std::ofstream file(target_ + "_shrubbery");

    if (file.is_open())
    {
        file << "               ,@@@@@@@,            \n";
        file << "         ,@@@@@@/@@,  .oo8888o.     \n";
        file << " ,&%&%&&%,@@@@@/@@@@@@,8888888/8o   \n";
        file << " ,%&%&&%&&%,@@@@@@@/@@@88888888/88  \n";
        file << "%&&%&%&/%&&%@@@@@/ /@@@88888888888  \n";
        file << " %&&%/ %&%&&@@@ V /@@@  `888888/88  \n";
        file << " `&%  /%&      |.|         |'|8     \n";
        file << "    |o|        | |         | |      \n";
        file << "    |.|        | |         | |      \n";
        file << "  _%|_       _%|_|       _%|_|      \n";
        file.close();
    }
    else
    {
        std::cout << "Error: could not open file" << std::endl;
    }
}