#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
  private:
    const std::string  _target;
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const std::string& _target);

    void  execute(Bureaucrat const& executor) const;
};

#endif
