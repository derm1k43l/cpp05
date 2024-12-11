#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

// circular dependency
class Bureaucrat; // Forward declaration

class AForm
{
    public:
        AForm(const std::string& name, const int signGrade, const int execGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string&      getName() const;
        int                     getSignGrade() const;
        int                     getExecGrade() const;
        bool                    isSigned() const;

        void                    beSigned(Bureaucrat& bureaucrat);
        void                    execute(Bureaucrat const& bureaucrat) const;

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class AlreadySignedException : public std::exception
        {
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            const char* what() const throw();
        };

    private:
        const std::string name_;
        bool              isSigned_;
        const int         signGrade_;
        const int         execGrade_;
        // pure virtual method
        virtual void      performAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);