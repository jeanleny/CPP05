#include <Bureaucrat.hpp>
#include <Form.hpp>

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

	Form f1;
	Form f2("b-64", false, 2, 4);
	Form f3("c-16", false, 2, 4);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << obj << std::endl;
	std::cout << obj1 << std::endl;
	f1.beSigned(obj1);
	f2.beSigned(obj1);
	try
	{
		f1.beSigned(obj1);
		f2.beSigned(obj1);
		f3.beSigned(obj);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		obj1.signForm(f3);
		obj.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
