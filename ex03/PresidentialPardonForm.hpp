/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:06:06 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 11:25:03 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class President : public AForm
{
    private:
        std::string _target;
    public:
        President();
        President(std::string target);
        President(const President& copy);
        President& operator=(const President& copy);
        ~President();

        std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;
};

#endif