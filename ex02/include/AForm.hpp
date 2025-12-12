#ifndef AFORM_HPP
# define AFORM_HPP

#include <Bureaucrat.hpp>

class AForm 
{
	public:
		AForm();
		AForm(std::string name, bool state, int sgrade, int egrade);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& rhs);
		~AForm();
	
		std::string	getName() const;
		bool		getSigned()const;
		int			getSignedGrade()const;
		int			getExecGrade()const;

		void beSigned(const Bureaucrat& signatory);
		virtual void execute(Bureaucrat const& executor) = 0;

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

std::ostream& operator<<(std::ostream& stream, const AForm& rhs);

#endif
