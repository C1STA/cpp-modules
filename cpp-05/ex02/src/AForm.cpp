#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("DefaultForm"), _isSigned(false), _gradeSign(130), _gradeExecute(100) {}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {}

AForm& AForm::operator=(const AForm& other)
{
  if (this != &other)
    this->_isSigned = other._isSigned;
  return *this;
}

AForm::~AForm() {}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
  if (_gradeSign > 150 || _gradeExecute > 150)
    throw GradeTooLowException();
  else if (_gradeSign < 1 || _gradeExecute < 1)
    throw GradeTooHighException();
}

const std::string& AForm::getName() const
{
  return _name;
}

bool  AForm::isSigned() const
{
  return _isSigned;
}

int  AForm::getGradeSign() const
{
  return _gradeSign;
}

int  AForm::getGradeExecute() const
{
  return _gradeExecute;
}

void  AForm::beSigned(const Bureaucrat& obj)
{
  if (obj.getGrade() > _gradeSign)
    throw GradeTooLowException();
  if (_isSigned)
    throw FormAlreadySignedException();
  _isSigned = true;
}

void  AForm::beExecuted(Bureaucrat const& executor) const
{
  if (!_isSigned)
    throw FormNotSignedException();
  else if (executor.getGrade() > _gradeExecute)
    throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
  std::string isSigned = "not signed";
  if (obj.isSigned())
    isSigned = "is signed";

  os << obj.getName() << ", form " << isSigned << ", needed grade to be signed is " << obj.getGradeSign() << " and grade to be executed is " << obj.getGradeExecute() << ".";
  return os;
}
