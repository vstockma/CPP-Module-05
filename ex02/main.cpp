/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:44:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 14:53:34 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bur("Hans", 3);

        ShrubberyCreationForm   form("tree");
        bur.signAForm(form);
        bur.executeForm(form);

        RobotomyRequestForm robot("Robot");
        bur.signAForm(robot);
        bur.executeForm(robot);

        PresidentialPardonForm pardon("Pardon");
        bur.signAForm(pardon);
        bur.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}