/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:06:00 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 14:34:31 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class Shrubbery : public AForm
{
    private:
        std::string _target;
    public:
        Shrubbery();
        Shrubbery(std::string target);
        Shrubbery(const Shrubbery& copy);
        Shrubbery& operator=(const Shrubbery& copy);
        ~Shrubbery();

        std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;
};

#endif