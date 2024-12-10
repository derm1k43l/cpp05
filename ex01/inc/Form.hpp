#pragma once

#include <iostream>
#include <string>

// circular dependency
class Bureaucrat; // Forward declaration

class Form
{
    public:
        Form(const std::string &name, const int signGrade, const int execGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string&      getName() const;
        int                     getSignGrade() const;
        int                     getExecGrade() const;
        bool                    isSigned() const;

        void                    beSigned(Bureaucrat &bureaucrat);

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

    private:
        const std::string name_;
        bool              isSigned_;
        const int         signGrade_;
        const int         execGrade_;
};

std::ostream& operator<<(std::ostream& os, const Form& form);