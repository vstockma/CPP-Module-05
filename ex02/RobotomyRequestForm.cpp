/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:20:14 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 14:46:53 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    _target = "Default";
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    if (target.empty())
        _target = "Unkown";
    else
        _target = target;
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
    *this = copy;
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    _target = copy._target;
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{ return _target; }

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeExecute() || !getIsSigned())
        throw GradeTooLowException();
    int i = 0;
    while (i < 7)
    {
        std::cout << "drilling\n";
        usleep(1000000);
        i++;
    }
    std::srand((std::time(NULL)));
    // Generate a random number between 0 and 1
    int random = std::rand() % 2;
    if (random == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}
