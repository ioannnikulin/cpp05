#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"

using std::string;
using std::exception;
using std::ostream;

class PresidentialPardonForm: public AForm {
private:
	static const string FORM_NAME;
	static const string DEFAULT_TARGET;
	static const int SIGN_GRADE = 25;
	static const int EXEC_GRADE = 5;
	string _target;

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

public:
	PresidentialPardonForm(const string &target);
	~PresidentialPardonForm();

	virtual void execute(const Bureaucrat &b) const;
};
#endif