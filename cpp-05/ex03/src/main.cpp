#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define GREEN "\033[32m"
#define WHITE "\033[0m"

int main()
{
  AForm*  shrub   = NULL;
  AForm*  robo    = NULL;
  AForm*  pres    = NULL;
  AForm*  invalid = NULL;
  try
  {
    std::srand(std::time(NULL));

    std::cout << GREEN "===== CREATING BUREAUCRATS & INTERNS=====" WHITE << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 145);
    Intern someRandomIntern;

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;

    std::cout << GREEN "\n===== CREATING FORMS (VALID) =====" WHITE << std::endl;
    shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    robo  = someRandomIntern.makeForm("robotomy request", "Bender");
    pres  = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

    std::cout << *shrub << std::endl;
    std::cout << *robo << std::endl;
    std::cout << *pres << std::endl;

    std::cout << GREEN "\n===== CREATING FORMS (INVALID) =====" WHITE << std::endl;
    invalid = someRandomIntern.makeForm("supply management", "42");

    std::cout << GREEN "\n===== ATTEMPT TO SIGN =====" WHITE << std::endl;
    worker.signForm(*shrub);
    boss.signForm(*shrub);
    boss.signForm(*robo);
    boss.signForm(*pres);

    std::cout << GREEN "\n===== ATTEMPT TO EXECUTE (GRADE TOO LOW) =====" WHITE << std::endl;
    worker.executeForm(*shrub);

    std::cout << GREEN "\n===== ATTEMPT TO EXECUTE =====" WHITE << std::endl;
    boss.executeForm(*shrub);
    boss.executeForm(*robo);
    boss.executeForm(*pres);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  delete shrub;
  delete robo;
  delete pres;
  delete invalid;

  return 0;
}
