/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:44:39 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/31 13:17:10 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat num1("hans", 150);
    Bureaucrat num2(num1);

    try
    {
        // num1.incrementGrade();
        num1.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    std::cout << num1.getName() << " has grade " << num1.getGrade() << std::endl;
    std::cout << num1.getGrade() << std::endl;
    std::cout << num2.getName() << " has grade " << num2.getGrade() << std::endl;
    return (0);
}