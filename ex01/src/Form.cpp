#include <Form.hpp>

Form::Form() : _name("A-38"), _signed(false), _signgrade(150), _execgrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, bool state, int sgrade, int egrade) :_name(name), _signed(state), _signgrade(sgrade), _execgrade(egrade)
{
	std::cout << "Form argument constructor called" << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), _signed(obj._signed), _signgrade(obj._signgrade), _execgrade(obj._execgrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "Form assignement overload called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, Form const& rhs)
{
	if (rhs.getSigned())
		std::cout << rhs.getName() << " : state is signed" << std::endl;
	else 
		std::cout << rhs.getName() << " : state is unsigned" << std::endl;
	std::cout << rhs.getName() << " : sign grade  is " << rhs.getSignedGrade() << std::endl;
	std::cout << rhs.getName() << " : exec grade is " << rhs.getExecGrade() << std::endl;
	return (stream);
}

Form::~Form()
{
	std::cout << "Form default destructor" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned()const
{
	return (_signed);
}

int	Form::getSignedGrade()const
{
	return (_signgrade);
}

int	Form::getExecGrade()const
{
	return (_execgrade);
}

void	Form::beSigned(const Bureaucrat& signatory)
{
	if (!this->_signed)
	{
		if (signatory.getGrade() < this->getSignedGrade())
		{
			std::cout << this->getName() << " is signed by " << signatory.getName() << std::endl;
			this->_signed = true;	
			return ;
		}
		else
		{
			std::cout << signatory.getName() << " couldn't sign " << this->getName() << " because grade is too low" << std::endl;
			throw Form::GradeTooLowException();
		}
	}
}
