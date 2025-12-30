#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
  private:
    const std::string  _target;
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    PresidentialPardonForm(const std::string& target);

    void  execute(Bureaucrat const& executor) const;
};

#endif
