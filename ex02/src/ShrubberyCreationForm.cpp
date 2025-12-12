#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SHRUB-27", false, 145, 137), _target("Marvin")
{
	std::cout << "default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("SHRUB-27", false, 145, 137), _target(_target)
{
	std::cout << "default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & obj) : AForm(obj), _target(obj._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) 
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > 137)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::string name = getTarget() + "_shrubbery";
	std::ofstream file(name.c_str());
	file << "               ,@@@@@@@," << std::endl <<
			"       ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl <<
			"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
			"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
			"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
			"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
			"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
			"       |o|        | |         | |" << std::endl <<
			"       |.|        | |         | |" << std::endl <<
			"   \\\\/ /_\\\\//_/__/  ,\\\\_//__\\/.  \\_//__/_" << std::endl;
			
	file.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}
