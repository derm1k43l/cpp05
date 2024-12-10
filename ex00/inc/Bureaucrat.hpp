#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    public:
        // canonical form
        Bureaucrat(std::string const& name, int grade); // Constructor
        Bureaucrat(Bureaucrat const& other); // Copy constructor
        Bureaucrat& operator=(Bureaucrat const& other); // Copy assignment operator
        ~Bureaucrat();

        // methods 
        std::string const   &getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        // exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

    private:
        std::string const name_;
        int               grade_;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);