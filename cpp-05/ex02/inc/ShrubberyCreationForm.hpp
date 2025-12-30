#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  private:
    const std::string  _target;
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const std::string& _target);

    void  execute(Bureaucrat const& executor) const;

    class FileManagementException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "the shrubbery file couldn't be opened.";
      }
    };
};

#endif
