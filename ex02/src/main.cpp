#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main()
{
	Bureaucrat				jack(137, "Jack");
	Bureaucrat				henry(145, "Henry");
	ShrubberyCreationForm	oui("Michel le iencli");
	std::cout << henry << std::endl;
	std::cout << jack << std::endl;
	std::cout << oui << std::endl;
	try 
	{
		henry.signForm(oui);
		jack.executeForm(oui);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << oui << std::endl;
}
