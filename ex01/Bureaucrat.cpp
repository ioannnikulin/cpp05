#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::cout;
using std::endl;
using std::exception;

const string Bureaucrat::DEFAULT_NAME = "Richard";

Bureaucrat::Bureaucrat():
	_name(DEFAULT_NAME)
	, _grade(DEFAULT_GRADE)
{
}

Bureaucrat::Bureaucrat(const string &name, int grade): 
	_name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other.getName())
{
	setGrade(other.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other) {
		return (*this);
	}
	// name uncopyable, const by subject
	setGrade(other.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

const string &Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	setGrade(getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
	setGrade(getGrade() + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

void Bureaucrat::signForm(Form &f) const {
	try {
		f.beSigned(*this);
		cout << getName() << " signed " << f.getName() << endl;
	} catch (exception &e) {
		cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << endl;
	}
}

ostream &operator<<(ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}