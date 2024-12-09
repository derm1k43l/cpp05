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
        ~Form();

        const std::string&      getName() const;
        int                     getSignGrade() const;
        int                     getExecGrade() const;
        bool                    isSigned() const;

        void                    beSigned(Bureaucrat &bureaucrat);

    private:
        const std::string name_;
        bool              isSigned_;
        const int         signGrade_;
        const int         execGrade_;
        // its here to prevent???
        Form &operator=(const Form &other);

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw()
            { return "Grade is too low"; }
        };
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw()
            { return "Grade is too high"; }
        };
        class AlreadySignedException : public std::exception
        {
            const char* what() const throw()
            { return "Form is already signed"; }
        };
};

//overload << operator
std::ostream& operator<<(std::ostream& os, const Form& form);
