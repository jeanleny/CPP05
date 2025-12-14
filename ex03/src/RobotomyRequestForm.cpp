#include <RobotomyRequestForm.hpp>
#include <AForm.hpp>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", false, 72, 45), _target("Marvin")
{
	std::cout << "default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("robotomy request", false, 72, 45), _target(_target)
{
	std::cout << "default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & obj) : AForm(obj), _target(obj._target)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) 
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > 45)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		std::cout << _target << " has been succesfully robotomized !" << std::endl;
		return ;
	}
	std::cout << _target << "'s robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}
