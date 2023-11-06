/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:20:24 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 14:53:06 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 60, 4)
{
    _target = "Default_ShrubberyCreationForm";
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 60, 4)
{
    if (target.empty())
        _target = "Unkown_shrubbery";
    else
        _target = target + "_shrubbery";
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
    *this = copy;
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    _target = copy._target;
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{ return _target; }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeExecute() || !getIsSigned())
        throw GradeTooLowException();
    std::ofstream file;
    file.open(_target.c_str());
    int i = 0;
    if (file.is_open())
    {
        while (i < 2)
        {
            file << "   *   " << std::endl;
            file << "  ***  " << std::endl;
            file << " ***** " << std::endl;
            file << "*******" << std::endl;
            file << "   |   " << std::endl;
            i++;
        }
    }
    else
        std::cerr << "Error with file" << std::endl;
}
