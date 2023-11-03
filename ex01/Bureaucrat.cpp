/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:07 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/02 16:07:50 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unkown Bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade) : _name(new_name)
{
    if (new_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (new_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = new_grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    _grade = copy._grade;
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

const char*    Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char*    Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade()
{
    if ((_grade - 1) < 1)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade -= 1;
}

void    Bureaucrat::decrementGrade()
{
    if ((_grade + 1) > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade += 1;
}

void    Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Bureaucrat " << _name << " couldn't sign " << form.getName() << " because " << std::endl;
        std::cerr << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
