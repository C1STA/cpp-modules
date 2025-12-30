#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeSign(130), _gradeExecute(100) {}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {}

Form& Form::operator=(const Form& other)
{
  if (this != &other)
    this->_isSigned = other._isSigned;
  return *this;
}

Form::~Form() {}

Form::Form(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
  if (_gradeSign > 150 || _gradeExecute > 150)
    throw GradeTooLowException();
  else if (_gradeSign < 1 || _gradeExecute < 1)
    throw GradeTooHighException();
}

const std::string& Form::getName() const
{
  return _name;
}

bool  Form::isSigned() const
{
  return _isSigned;
}

int  Form::getGradeSign() const
{
  return _gradeSign;
}

int  Form::getGradeExecute() const
{
  return _gradeExecute;
}

void  Form::beSigned(const Bureaucrat& obj)
{
  if (obj.getGrade() > _gradeSign)
    throw GradeTooLowException();
  if (_isSigned)
    throw FormAlreadySignedException();
  _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
  std::string isSigned = "not signed";
  if (obj.isSigned())
    isSigned = "is signed";

  os << obj.getName() << ", form " << isSigned << ", needed grade to be signed is " << obj.getGradeSign() << " and grade to be executed is " << obj.getGradeExecute() << ".";
  return os;
}
