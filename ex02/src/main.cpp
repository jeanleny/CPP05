#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main()
{
	Bureaucrat andy(5, "Andy");
	Bureaucrat jim(25, "Jim");
	Bureaucrat kevin(70, "Kevin");
	Bureaucrat cathy(140, "Cathy");

	ShrubberyCreationForm scf("random yard");
	RobotomyRequestForm rrf("local goat");
	PresidentialPardonForm ppf("random bloke");

	std::cout << "\n" << cathy << std::endl;
	std::cout << scf << "\n" << std::endl;
	try 
	{
		andy.executeForm(scf);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << cathy << std::endl;
	std::cout << scf << "\n" << std::endl;
	try 
	{
		cathy.signForm(scf);
		cathy.executeForm(scf);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
