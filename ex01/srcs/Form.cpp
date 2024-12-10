#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(const std::string& name, const int signGrade, const int execGrade) : name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name_(other.name_), isSigned_(other.isSigned_), signGrade_(other.signGrade_), execGrade_(other.execGrade_)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        isSigned_ = other.isSigned_;
    return *this;
}

const std::string& Form::getName() const
{
    return name_;
}
int Form::getSignGrade() const
{
    return signGrade_;
}
int Form::getExecGrade() const
{
    return execGrade_;
}
bool Form::isSigned() const
{
    return isSigned_;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::AlreadySignedException::what() const throw()
{
    return "Form is already signed";
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade_)
        throw GradeTooLowException();
    if (isSigned_)
        throw AlreadySignedException();
    isSigned_ = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << " -- sign grade -- " << form.getSignGrade() << " -- exec grade -- " << form.getExecGrade() << " -- signed -- " << form.isSigned();
    return os;
}