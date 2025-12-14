#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main()
{
	Intern titouan;
	AForm *test = titouan.makeForm("meokuyt", "rienguou");
	std::cout << *test << std::endl;
}
