#include <Bureaucrat.hpp>
#include <AForm.hpp>

Bureaucrat::Bureaucrat () : _name("Default"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat argument constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): _name(obj._name), _grade(obj._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat const& rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (stream);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::gradeIncrement()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	_grade++;
}

void	Bureaucrat::gradeDecrement()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	_grade--;
}

void	Bureaucrat::signForm(AForm &f)
{
	f.beSigned(*this);
	std::cout << f.getName() << " is signed by " << getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	std::cout << getName() << " executed " << form.getName() << std::endl;
}
