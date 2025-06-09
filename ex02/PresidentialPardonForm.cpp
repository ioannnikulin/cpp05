#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

const string PresidentialPardonForm::FORM_NAME = "Presidential Pardon Form";
const string PresidentialPardonForm::DEFAULT_TARGET = "nobody";

PresidentialPardonForm::PresidentialPardonForm():
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE)
	, _target(DEFAULT_TARGET)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
	, _target(other._target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const string &target):
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE)
	, _target(target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other) {
		return (*this);
	}
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const {
	AForm::preexecutionCheck(b);
	cout << _target << " has been pardoned by Zaphod Beeblebrox" << endl;
}