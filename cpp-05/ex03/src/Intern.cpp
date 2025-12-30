#include <string>
#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
  return *this;
}

Intern::~Intern() {}

AForm*  Intern::createShrubbery(std::string const& target) {
  return new ShrubberyCreationForm(target);
}

AForm*  Intern::createRobotomy(std::string const& target) {
  return new RobotomyRequestForm(target);
}

AForm*  Intern::createPresidential(std::string const& target) {
  return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(std::string const& name, std::string const& target)
{
  std::string const  names[] =
  {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };

  AForm*(Intern::*funcPtr[])(std::string const&) =
  {
    &Intern::createShrubbery,
    &Intern::createRobotomy,
    &Intern::createPresidential
  };

  int n = sizeof(funcPtr) / sizeof(funcPtr[0]);

  for (int i = 0; i < n; i++)
  {
    if (names[i] == name)
    {
      std::cout << "Intern creates " << name << "." << std::endl;
      return (this->*funcPtr[i])(target);
    }
  }
  std::cout << "Intern couldn't find form named " << name << "." << std::endl;
  return 0;
}
