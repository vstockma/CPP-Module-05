/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:50:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 11:48:49 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _grade_sign_it;
        const int           _grade_execute;
    public:
        AForm();
        AForm(std::string _new_name, int new_grade_sign_it, int new_grade_execute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm();

        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        std::string getName() const;
        int         getGradeSignIt() const;
        int         getGradeExecute() const;
        bool        getIsSigned() const;
        void        beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& copy);

#endif