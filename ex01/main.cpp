/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:44:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 11:34:45 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat num1("hans", 110);
        Form form("paper", 120, 120);
        num1.incrementGrade();
        // num1.decrementGrade();
        std::cout << form << std::endl;
        form.beSigned(num1);
        num1.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}