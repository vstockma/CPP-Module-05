/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:44:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 16:01:19 by vstockma         ###   ########.fr       */
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
        Bureaucrat bur("Hans", 2);

        Shrubbery   form("ascii_tree");
        bur.signAForm(form);
        bur.executeForm(form);

        Robot robot("Robot");
        bur.signAForm(robot);
        bur.executeForm(robot);

        President pardon("Pardon");
        bur.signAForm(pardon);
        bur.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}