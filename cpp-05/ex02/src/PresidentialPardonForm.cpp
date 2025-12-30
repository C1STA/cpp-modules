#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("Default Presidential") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
  if (this != &other)
    AForm::operator=(other);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presidential pardon", 25, 5), _target(target) {}

void  PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
  beExecuted(executor);
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
