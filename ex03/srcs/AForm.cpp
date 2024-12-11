#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

// Constructor
AForm::AForm(const std::string& name, const int signGrade, const int execGrade)
    : name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : name_(other.name_), isSigned_(other.isSigned_), signGrade_(other.signGrade_), execGrade_(other.execGrade_)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        isSigned_ = other.isSigned_;
    return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return name_;
}
int AForm::getSignGrade() const
{
    return signGrade_;
}
int AForm::getExecGrade() const
{
    return execGrade_;
}
bool AForm::isSigned() const
{
    return isSigned_;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return "Form is already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade_)
        throw GradeTooLowException();
    if (isSigned_)
        throw AlreadySignedException();
    isSigned_ = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() << " -- sign grade -- " << form.getSignGrade() << " -- exec grade -- " << form.getExecGrade() << " -- signed -- " << form.isSigned();
    return os;
}

void AForm::execute(const Bureaucrat& excutor) const
{
    if (!isSigned_)
        throw FormNotSignedException();
    if (excutor.getGrade() > execGrade_)
        throw GradeTooLowException();
    performAction();
}