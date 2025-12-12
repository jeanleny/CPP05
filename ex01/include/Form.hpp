#ifndef FORM_HPP
# define FORM_HPP

#include <Bureaucrat.hpp>

class Form 
{
	public:
		Form();
		Form(std::string name, bool state, int sgrade, int egrade);
		Form(const Form& obj);
		Form& operator=(const Form& rhs);
		~Form();
		void beSigned(const Bureaucrat& signatory);
		std::string	getName() const;
		bool		getSigned()const;
		int			getSignedGrade()const;
		int			getExecGrade()const;


	class GradeTooHighException : public std::exception
	{
		public :
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public :
			const char* what() const throw();
	};


	private :
		const std::string	_name;
		bool				_signed;
		const int			_signgrade;
		const int			_execgrade;
};

std::ostream& operator<<(std::ostream& stream, const Form& rhs);

#endif
