/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:20:24 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 14:45:50 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery() : AForm("Shrubbery", 60, 4)
{
    _target = "Default_shrubbery";
    std::cout << "Shrubbery Default constructor called" << std::endl;
}

Shrubbery::Shrubbery(std::string target) : AForm("Shrubbery", 60, 4)
{
    if (target.empty())
        _target = "Unkown_shrubbery";
    else
        _target = target + "_shrubbery";
    std::cout << "Shrubbery constructor called" << std::endl;
}

Shrubbery::Shrubbery(const Shrubbery& copy)
{
    *this = copy;
    std::cout << "Shrubbery Copy constructor called" << std::endl;
}

Shrubbery& Shrubbery::operator=(const Shrubbery& copy)
{
    _target = copy._target;
    std::cout << "Shrubbery Copy assignment operator called" << std::endl;
    return (*this);
}

Shrubbery::~Shrubbery()
{
    std::cout << "Shrubbery Destructor called" << std::endl;
}

std::string Shrubbery::getTarget() const
{ return _target; }

void Shrubbery::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeExecute() || !getIsSigned())
        throw GradeTooLowException();
    std::ofstream file;
    file.open(_target.c_str());
    if (file.is_open())
    {
        file << "   *   " << std::endl;
        file << "  ***  " << std::endl;
        file << " ***** " << std::endl;
        file << "*******" << std::endl;
        file << "   |   " << std::endl;
    }
    else
        std::cerr << "Error with file" << std::endl;
}
