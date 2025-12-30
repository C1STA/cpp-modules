#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
  if (this != &other)
    this->_grade = other._grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    _grade = grade;
}

const std::string& Bureaucrat::getName() const
{
  return this->_name;
}

int Bureaucrat::getGrade() const
{
  return this->_grade;
}

void  Bureaucrat::promote()
{
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  else
    this->_grade--;
}

void  Bureaucrat::demote()
{
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  else
    this->_grade++;
}

void  Bureaucrat::signForm(Form& obj)
{
  try
  {
    obj.beSigned(*this);
    std::cout << _name << " signed " << obj.getName() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << _name << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
  }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return os;
}
