/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:05:56 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 15:21:23 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    *this = copy;
    std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    std::cout << "Intern Copy assignment operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

AForm*    Intern::makeForm(std::string form_name, std::string form_target) const
{
    const std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    
    int i = 0;
    while (i < 3)
    {
        if (forms[i] == form_name)
            break ;
        i++;
    }
    switch (i)
    {
        case 0: return new ShrubberyCreationForm(form_target);
        case 1: return new RobotomyRequestForm(form_target);
        case 2: return new PresidentialPardonForm(form_target);
            break ;
        default:
            std::cout << "This kind of Form does not exist" << std::endl;
    }
    return (NULL);
}

