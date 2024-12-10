#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>


class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

    private:
        const std::string   target_;
        void                performAction() const override;
};