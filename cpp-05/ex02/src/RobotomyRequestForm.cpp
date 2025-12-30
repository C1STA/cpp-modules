#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("Default Robotomy") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
  if (this != &other)
    AForm::operator=(other);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy request", 72, 45), _target(target) {}

void  RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
  beExecuted(executor);
  std::cout << "*** Drilling Noises ***" << std::endl;
  if (std::rand() % 2)
    std::cout << _target << " has been robotomized successfully." << std::endl;
  else
    std::cout << _target << " couldn't be robotomized." << std::endl;
}

