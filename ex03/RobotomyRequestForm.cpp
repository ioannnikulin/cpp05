#include <stdlib.h>

#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

const string RobotomyRequestForm::FORM_NAME = "Robotomy Request Form";
const string RobotomyRequestForm::DEFAULT_TARGET = "nobody";

RobotomyRequestForm::RobotomyRequestForm():
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE)
	, _target(DEFAULT_TARGET)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
	, _target(other._target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const string &target):
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE)
	, _target(target)
{
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other) {
		return (*this);
	}
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
	AForm::preexecutionCheck(b);
	cout << "BRRRRRRRRRRRRRRRR";
	if (rand() % 2) {
		cout << "KCHKCHKCHPLINNNNG! Drill has broken, robotomy failed" << endl;
	} else {
		cout << "INK! " << _target << " has been robotomized successfully" << endl;
	}
}