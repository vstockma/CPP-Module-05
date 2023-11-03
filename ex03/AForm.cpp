/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:51:40 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 15:58:35 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unkown"), _grade_sign_it(150), _grade_execute(150)
{
    _is_signed = false;
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string _new_name, int new_grade_sign_it, int new_grade_execute) : _name(_new_name), _grade_sign_it(new_grade_sign_it), _grade_execute(new_grade_execute)
{
    if (new_grade_sign_it < 1 || new_grade_execute < 1)
        throw AForm::GradeTooHighException();
    else if (new_grade_sign_it > 150 || new_grade_execute > 150)
        throw AForm::GradeTooLowException();
    _is_signed = false;
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _grade_sign_it(copy._grade_sign_it), _grade_execute(copy._grade_execute)
{
    *this = copy;
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
    _is_signed = copy._is_signed;
    std::cout << "AForm Copy assignment operator called" << std::endl;
    return (*this);
}

const char*    AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char*    AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

AForm::~AForm()
{ std::cout << "AForm Destructor called" << std::endl; }

std::string AForm::getName() const
{ return (_name); }

int AForm::getGradeSignIt() const
{ return (_grade_sign_it); }

int AForm::getGradeExecute() const
{ return (_grade_execute); }

bool AForm::getIsSigned() const
{ return (_is_signed); }

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _grade_sign_it)
        _is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& copy)
{
    os << "Name: " << copy.getName() << " | Signed Status: " << copy.getIsSigned() << " | Grade to sign in: " << copy.getGradeSignIt() << " | Grade to execute: " << copy.getGradeExecute(); 
    return (os);
}

