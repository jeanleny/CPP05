#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
		void execute(Bureaucrat const& executor) const;
		std::string getTarget() const;
	private :
		std::string _target;
};

#endif
