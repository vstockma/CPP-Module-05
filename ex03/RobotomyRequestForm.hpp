/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:06:03 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/03 12:16:10 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class Robot : public AForm
{
    private:
        std::string _target;
    public:
        Robot();
        Robot(std::string target);
        Robot(const Robot& copy);
        Robot& operator=(const Robot& copy);
        ~Robot();

        std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;
};

#endif