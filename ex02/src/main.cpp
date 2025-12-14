#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main()
{
	try
	{
		Bureaucrat						jack(0, "Jack");
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat						henry(25, "Henry");
	PresidentialPardonForm			oui("Michel le iencli");
	std::cout << henry << std::endl;
	std::cout << oui << std::endl;
	try 
	{
		henry.signForm(oui);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << oui << std::endl;
}
