#include <string>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("Default Shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
  if (this != &other)
    AForm::operator=(other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", 145, 137), _target(target) {}

static const char* asciiTree =
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣞⣓⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡆⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠏⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡵⣆⣰⢦⡟⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⢀⡞⠁⡴⣄⠀⠀⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⢰⣋⣀⠀⣀⡀⠀⣠⣄⣠⠭⠄⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⡎⠀⠉⠁⠈⠒⠃⣤⡈⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⣠⠏⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⣙⡆⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⣓⠏⠧⣔⡉⣇⡴⠒⠢⡏⠉⠉⠠⡄⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⡔⠁⠀⠀⠧⠃⠀⠉⠀⠀⠀⠀⠸⣽⠀⠀⢳⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⣇⣤⠀⠀⠀⠀⢀⣤⡀⠀⡖⣆⡴⢦⣰⠛⡇⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⡎⠁⠓⠉⠉⠉⠃⠀⠉⠉⠀⠀⠀⢠⢄⡀⣇⠀⠀⠀⠀⠀\n"
"⠀⠀⣀⡖⠁⠀⠀⠀⠀⠧⠝⠀⠀⠀⠀⠀⠀⠀⠓⠋⠀⠀⠉⡆⠀⠀\n"
"⠀⠀⡧⣲⠖⣆⣀⣀⣀⡀⠀⢀⣀⡀⠀⠀⡰⠂⠦⡴⠛⡛⠀⠀⠀⠀\n"
"⠀⠀⢰⠃⠀⣠⠶⡄⠀⠀⠉⠋⠁⠀⠈⠉⠉⠀⢀⣤⠀⠀⢡⡀⠀⠀\n"
"⢀⡤⠇⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠓⠚⠀⠀⠀⣹⡆\n"
"⢯⡀⠤⠒⢆⠀⠀⢀⣄⢀⡤⢶⡤⠒⡆⡠⠶⡀⢀⠞⠁⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠈⠓⠋⠀⡏⠀⠀⠀⠀⠀⡇⠁⠀⠀⠉⠁⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠒⠒⠖⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";

void  ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
  beExecuted(executor);
  const std::string  filename = _target + "_shrubbery";
  std::ofstream  out(filename.c_str(), std::ios::out | std::ios::trunc);
  if (!out)
    throw FileManagementException();
  out << asciiTree;
}
