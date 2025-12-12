#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat 
{
	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat& operator=(const Bureaucrat &rhs);
		~Bureaucrat();
		void		signForm(Form& f);
		int			getGrade() const;
		std::string	getName() const;
		void		gradeIncrement();
		void		gradeDecrement();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& stream ,Bureaucrat const& rhs); 

#endif 
