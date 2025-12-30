#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
  private:
    AForm*  createShrubbery(std::string const& target);
    AForm*  createRobotomy(std::string const& target);
    AForm*  createPresidential(std::string const& target);
  public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm*  makeForm(std::string const& name, std::string const& target);
};

#endif
