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
	Intern
	Form*
	someRandomIntern;
	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch (std::exception & e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}
