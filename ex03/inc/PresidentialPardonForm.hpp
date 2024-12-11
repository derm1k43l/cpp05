#pragma once
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

    private:
        const std::string   target_;
        void                performAction() const override;
};