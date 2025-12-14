#include <AForm.hpp>

AForm::AForm() : _name("A-38"), _signed(false), _signgrade(150), _execgrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, bool state, int sgrade, int egrade) :_name(name), _signed(state), _signgrade(sgrade), _execgrade(egrade)
{
	std::cout << "AForm argument constructor called" << std::endl;
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signed(obj._signed), _signgrade(obj._signgrade), _execgrade(obj._execgrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	std::cout << "AForm assignement overload called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, AForm const& rhs)
{
	if (rhs.getSigned())
		stream << rhs.getName() << " : state is signed" << std::endl;
	else 
		stream << rhs.getName() << " : state is unsigned" << std::endl;
	stream << rhs.getName() << " : sign grade  is " << rhs.getSignedGrade() << std::endl;
	stream << rhs.getName() << " : exec grade is " << rhs.getExecGrade();
	return (stream);
}

AForm::~AForm()
{
	std::cout << "AForm default destructor" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned()const
{
	return (_signed);
}

int	AForm::getSignedGrade()const
{
	return (_signgrade);
}

int	AForm::getExecGrade()const
{
	return (_execgrade);
}

void	AForm::beSigned(const Bureaucrat& signatory)
{
	if (this->_signed)
	{
		std::cout << signatory.getName() << " couldn't sign " << this->getName() << " because is already signed" << std::endl;
		return ;
	}
	if (signatory.getGrade() <= this->getSignedGrade())
	{
		_signed = true;
		return ;
	}
	else
	{
		std::cout << signatory.getName() << " couldn't sign " << this->getName() << " because grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
}
