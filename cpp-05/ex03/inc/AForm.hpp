#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeSign;
    const int         _gradeExecute;
  public:
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    AForm(const std::string& name, int gradeSign, int gradeExecute);

    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeSign() const;
    int                 getGradeExecute() const;

    virtual void  execute(Bureaucrat const& executor) const = 0;
    void  beExecuted(Bureaucrat const& executor) const;
    void  beSigned(const Bureaucrat& obj);

    class GradeTooHighException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "its grade is too high.";
      }
    };

    class GradeTooLowException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "its grade is too low.";
      }
    };

    class FormNotSignedException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "form is not signed.";
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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
