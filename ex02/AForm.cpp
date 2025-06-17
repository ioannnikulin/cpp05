#include "AForm.hpp"

const string AForm::DEFAULT_NAME = "Form";

AForm::AForm():
	_name(DEFAULT_NAME)
	, _signGrade(DEFAULT_SIGN_GRADE)
	, _execGrade(DEFAULT_EXEC_GRADE)
{
}

AForm::AForm(const string &name, int signGrade, int execGrade): 
	_name(name)
	, _isSigned(false)
{
	setSignGrade(signGrade);
	setExecGrade(execGrade);
}

AForm::AForm(const AForm &other):
	_name(other.getName())
	, _isSigned(false)
{
	setSignGrade(other.getSignGrade());
	setExecGrade(other.getExecGrade());
}

AForm &AForm::operator=(const AForm &other) {
	if (this == &other) {
		return (*this);
	}
	// name not reassignable, subject requires const
	setSignGrade(other.getSignGrade());
	setExecGrade(other.getExecGrade());
	_isSigned = false;
	return (*this);
}

AForm::~AForm() {
}

const string &AForm::getName() const {
	return _name;
}

void AForm::checkGradeLimits(int grade) {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
}

void AForm::setSignGrade(int grade) {
	checkGradeLimits(grade);
	_signGrade = grade;
}

void AForm::setExecGrade(int grade) {
	checkGradeLimits(grade);
	_execGrade = grade;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (getSignGrade() < b.getGrade()) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

bool AForm::isSigned() const {
	return _isSigned;
}

void AForm::preexecutionCheck(const Bureaucrat &b) const {
	if (!isSigned()) {
		throw NoSignatureException();
	}
	if (b.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *AForm::NoSignatureException::what() const throw() {
	return ("Form not signed yet");
}

ostream &operator<<(ostream &os, const AForm &f) {
	os << "Form " << f.getName()
		<< ", sign grade " << f.getSignGrade()
		<< ", execution grade " << f.getExecGrade()
	;
	return os;
}
