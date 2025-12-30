#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[32m"
#define WHITE "\033[0m"

int main()
{
    try
    {
        std::cout << GREEN "===== CREATING BUREAUCRATS =====" WHITE << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 140);

        std::cout << boss << std::endl;
        std::cout << worker << std::endl;

        std::cout << GREEN "\n===== CREATING FORMS =====" WHITE << std::endl;
        Form secret("TopSecret", 10, 5);
        Form paper("Paper", 150, 150);

        std::cout << secret << std::endl;
        std::cout << paper << std::endl;

        std::cout << GREEN "\n===== ATTEMPT TO SIGN =====" WHITE << std::endl;

        worker.signForm(secret);
        boss.signForm(secret);
        worker.signForm(paper);
        worker.signForm(paper);

        std::cout << GREEN "\n===== FINAL STATUS OF FORMS =====" WHITE << std::endl;
        std::cout << secret << std::endl;
        std::cout << paper << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
