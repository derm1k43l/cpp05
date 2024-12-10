#include "../inc/Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(std::string const& name, int grade) : name_(name), grade_(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const& other) : name_(other.name_), grade_(other.grade_) {}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    if (this != &other)
        grade_ = other.grade_;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Methods
std::string const& Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::incrementGrade()
{
    if (grade_ - 1 <= 0)
        throw GradeTooHighException();
    grade_--;
}

void Bureaucrat::decrementGrade()
{
    if (grade_ + 1 > 150)
        throw GradeTooLowException();
    grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
    os << bureaucrat.getName() << " BUREAUCRAT -- grade -- " << bureaucrat.getGrade();
    return os;
}