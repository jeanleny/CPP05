#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();
		void execute(Bureaucrat const& executor) const;
		std::string getTarget() const;
	private :
		std::string _target;
};

#endif
