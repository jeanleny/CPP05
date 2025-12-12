#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "default ShrubberyCreationForm constructor called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & obj) : AForm(obj)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
	(void)executor;
	std::cout << "oui" << std::endl;
}
