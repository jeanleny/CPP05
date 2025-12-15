#include <Intern.hpp>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	(void)obj;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string fname, std::string ftarget)
{
	int i;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (i = 0; i < 3 ; i++)
	{
		if (fname == forms[i])
			break ;
	}
	switch (i)
	{
		case 0 :
			return (new ShrubberyCreationForm(ftarget));
		case 1 :
			return (new RobotomyRequestForm(ftarget));
		case 2 :
			return (new PresidentialPardonForm(ftarget));
		default :
			std::cout << "Intern couldn't create the form, " << fname << " is unkown" << std::endl;
			return (NULL);
	}
}
