#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

#include "AForm.hpp"

using std::string;
using std::exception;
using std::ostream;

class RobotomyRequestForm: public AForm {
private:
	static const string FORM_NAME;
	static const string DEFAULT_TARGET;
	static const int SIGN_GRADE = 72;
	static const int EXEC_GRADE = 45;
	string _target;

	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

public:
	RobotomyRequestForm(const string &target);
	~RobotomyRequestForm();

	virtual void execute(const Bureaucrat &b) const;
};
#endif
