#include <Bureaucrat.hpp>

int main()
{
	try 
	{
		Bureaucrat(151, "Bill");
		std::cout << "151" << std::endl;
		Bureaucrat(150, "Jackson");
		std::cout << "150" << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cerr <<  e.what() << std::endl;
	}
	Bureaucrat obj(150, "Philip");
	Bureaucrat obj1(1, "Bobby bob");
	try
	{
		obj.gradeIncrement();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		obj1.gradeDecrement();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << obj << std::endl;
	std::cout << obj1 << std::endl;
}
