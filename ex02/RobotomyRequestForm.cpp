/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:20:14 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 16:02:50 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

Robot::Robot() : AForm("Robot", 72, 45)
{
    _target = "Default";
    std::cout << "Robot Default constructor called" << std::endl;
}

Robot::Robot(std::string target) : AForm("Robot", 72, 45)
{
    if (target.empty())
        _target = "Unkown";
    else
        _target = target;
    std::cout << "Robot constructor called" << std::endl;
}

Robot::Robot(const Robot& copy)
{
    *this = copy;
    std::cout << "Robot Copy constructor called" << std::endl;
}

Robot& Robot::operator=(const Robot& copy)
{
    _target = copy._target;
    std::cout << "Robot Copy assignment operator called" << std::endl;
    return (*this);
}

Robot::~Robot()
{
    std::cout << "Robot Destructor called" << std::endl;
}

std::string Robot::getTarget() const
{ return _target; }

void    Robot::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeExecute() || !getIsSigned())
        throw GradeTooLowException();
    int i = 0;
    while (i < 10)
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
