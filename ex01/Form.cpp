/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:51:40 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/02 15:38:25 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Unkown"), _grade_sign_it(150), _grade_execute(150)
{
    _is_signed = false;
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string _new_name, int new_grade_sign_it, int new_grade_execute) : _name(_new_name), _grade_sign_it(new_grade_sign_it), _grade_execute(new_grade_execute)
{
    if (new_grade_sign_it < 1 || new_grade_execute < 1)
        throw Form::GradeTooHighException();
    else if (new_grade_sign_it > 150 || new_grade_execute > 150)
        throw Form::GradeTooLowException();
    _is_signed = false;
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _grade_sign_it(copy._grade_sign_it), _grade_execute(copy._grade_execute)
{
    *this = copy;
    std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    _is_signed = copy._is_signed;
    std::cout << "Form Copy assignment operator called" << std::endl;
    return (*this);
}

const char*    Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char*    Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

Form::~Form()
{ std::cout << "Form Destructor called" << std::endl; }

std::string Form::getName() const
{ return (_name); }

int Form::getGradeSignIt() const
{ return (_grade_sign_it); }

int Form::getGradeExecute() const
{ return (_grade_execute); }

bool Form::getIsSigned() const
{ return (_is_signed); }

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _grade_sign_it)
        _is_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& copy)
{
    os << "Name: " << copy.getName() << " | Signed Status: " << copy.getIsSigned() << " | Grade to sign in: " << copy.getGradeSignIt() << " | Grade to execute: " << copy.getGradeExecute(); 
    return (os);
}

