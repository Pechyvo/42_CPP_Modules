#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    protected:
        virtual void executeAction(Bureaucrat const & executor) const;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        std::string getTarget() const;
};

#endif