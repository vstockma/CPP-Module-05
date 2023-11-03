/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:13:40 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 12:07:16 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

President::President() : AForm("President", 25, 5)
{
    _target = "Default";
    std::cout << "President Default constructor called" << std::endl;
}

President::President(std::string target) : AForm("President", 25, 5)
{
    if (target.empty())
        _target = "Unkown";
    else
        _target = target;
    std::cout << "President constructor called" << std::endl;
}

President::President(const President& copy)
{
    *this = copy;
    std::cout << "President Copy constructor called" << std::endl;
}

President& President::operator=(const President& copy)
{
    _target = copy._target;
    std::cout << "President Copy assignment operator called" << std::endl;
    return (*this);
}

President::~President()
{
    std::cout << "President Destructor called" << std::endl;
}

std::string President::getTarget() const
{ return _target; }

void    President::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeExecute() || !getIsSigned())
        throw GradeTooLowException();
     std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
