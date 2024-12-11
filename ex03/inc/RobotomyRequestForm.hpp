#pragma once
#include "AForm.hpp"
#include <string>


class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

    private:
        const std::string   target_;
        void                performAction() const override;
};