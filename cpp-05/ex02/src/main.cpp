#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define GREEN "\033[32m"
#define WHITE "\033[0m"

int main()
{
  AForm* shrub = NULL;
  AForm* robo  = NULL;
  AForm* pres  = NULL;
  try
  {
    std::srand(std::time(NULL));

    std::cout << GREEN "===== CREATING BUREAUCRATS =====" WHITE << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 145);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;

    std::cout << GREEN "\n===== CREATING FORMS =====" WHITE << std::endl;
    shrub = new ShrubberyCreationForm("home");
    robo  = new RobotomyRequestForm("Bender");
    pres  = new PresidentialPardonForm("Arthur Dent");

    std::cout << *shrub << std::endl;
    std::cout << *robo << std::endl;
    std::cout << *pres << std::endl;

    std::cout << GREEN "\n===== ATTEMPT TO EXECUTE (NOT SIGNED) =====" WHITE << std::endl;
    boss.executeForm(*shrub);

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

  return 0;
}
