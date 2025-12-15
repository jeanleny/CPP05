#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main()
{
	Intern 		titouan;
	std::cout << "\n Robotomy request" << std::endl;
	Bureaucrat	pam(45, "Pam");
	AForm *rr = titouan.makeForm("robotomy request", "local goat");
	std::cout << *rr << std::endl;
	pam.signForm(*rr);
	pam.executeForm(*rr);
	std::cout << *rr << std::endl;
		
	
	std::cout << "\n Shrubbery Creation" << std::endl;
	Bureaucrat dwight(137, "Dwight");
	AForm *sc = titouan.makeForm("shrubbery creation", "random yard");
	std::cout << *sc << std::endl;
	dwight.signForm(*sc);
	dwight.executeForm(*sc);
	std::cout << *sc << std::endl;


	std::cout << "\n Presidential pardon" << std::endl;
	Bureaucrat michael(5, "Michael");
	AForm *pp = titouan.makeForm("presidential pardon", "random bloke");
	std::cout << *pp << std::endl;
	michael.signForm(*pp);
	michael.executeForm(*pp);
	std::cout << *pp << std::endl;
	std::cout << std::endl;
	AForm *w = titouan.makeForm("wut", "mah boi");
	(void)*w;

	delete pp;
	delete sc;
	delete rr;
}
