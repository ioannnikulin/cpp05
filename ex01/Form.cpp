#include "Form.hpp"

const string Form::DEFAULT_NAME = "Form";

Form::Form():
	_name(DEFAULT_NAME)
	, _signGrade(DEFAULT_SIGN_GRADE)
	, _execGrade(DEFAULT_EXEC_GRADE)
{
}

Form::Form(const string &name, int signGrade, int execGrade): 
	_name(name)
	, _isSigned(false)
{
	setSignGrade(signGrade);
	setExecGrade(execGrade);
}

Form::Form(const Form &other):
	_name(other.getName())
	, _isSigned(false)
{
	setSignGrade(other.getSignGrade());
	setExecGrade(other.getExecGrade());
}

Form &Form::operator=(const Form &other) {
	if (this == &other) {
		return (*this);
	}
	// name not reassignable, subject requires const
	setSignGrade(other.getSignGrade());
	setExecGrade(other.getExecGrade());
	_isSigned = false;
	return (*this);
}

Form::~Form() {
}

const string &Form::getName() const {
	return _name;
}

void Form::checkGradeLimits(int grade) {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
}

void Form::setSignGrade(int grade) {
	checkGradeLimits(grade);
	_signGrade = grade;
}

void Form::setExecGrade(int grade) {
	checkGradeLimits(grade);
	_execGrade = grade;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &b) {
	if (getSignGrade() < b.getGrade()) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

bool Form::isSigned() const {
	return _isSigned;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

ostream &operator<<(ostream &os, const Form &f) {
	os << "Form " << f.getName()
		<< ", sign grade " << f.getSignGrade()
		<< ", execution grade " << f.getExecGrade()
	;
	return os;
}
