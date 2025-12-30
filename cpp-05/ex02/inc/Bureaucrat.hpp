#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
  private:
    const std::string _name;
    int               _grade;
  public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(const std::string& name, int grade);

    const std::string& getName() const;
    int                getGrade() const;

    void  promote();
    void  demote();

    void  signForm(AForm& obj);

    void  executeForm(AForm const& form) const;

    class GradeTooHighException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "grade too high.";
      }
    };

    class GradeTooLowException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "grade too low.";
      }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
