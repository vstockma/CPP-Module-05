/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:44:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 11:14:59 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat num1("hans", 1);
        Bureaucrat num2(num1);
        num1.incrementGrade();
        // num1.decrementGrade();
        std::cout << num1.getName() << " has grade " << num1.getGrade() << std::endl;
        std::cout << num1.getGrade() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return (0);
}