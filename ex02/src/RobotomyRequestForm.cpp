#include <RobotomyRequestForm.hpp>
#include <AForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() : AForm("ROBOTOMY-G59", false, 72, 45), _target("Marvin")
{
	std::cout << "default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("ROBOTOMY-G59", false, 72, 45), _target(_target)
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
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}
