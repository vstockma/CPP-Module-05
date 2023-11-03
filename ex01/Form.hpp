/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:50:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/02 15:50:31 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_sign_it;
        const int _grade_execute;
    public:
        Form();
        Form(std::string _new_name, int new_grade_sign_it, int new_grade_execute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        std::string getName() const;
        int         getGradeSignIt() const;
        int         getGradeExecute() const;
        bool        getIsSigned() const;
        void        beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, Form& copy);

#endif