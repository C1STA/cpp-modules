#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
  private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeSign;
    const int         _gradeExecute;
  public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    Form(const std::string& name, int gradeSign, int gradeExecute);

    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeSign() const;
    int                 getGradeExecute() const;

    void  beSigned(const Bureaucrat& obj);

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

    class FormAlreadySignedException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "form is already signed.";
      }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
