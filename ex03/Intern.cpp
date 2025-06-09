#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

const string Intern::AVAILABLE_FORMS_NAMES[] = {
	"shrubbery creation"
	, "robotomy request"
	, "presidential pardon"
};

AForm* Intern::createShrubberyCreationForm(const string &target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const string &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const string &target) {
	return new PresidentialPardonForm(target);
}

const Intern::FormCreator Intern::AVAILABLE_FORMS_CONSTRUCTORS[] = {
	&Intern::createShrubberyCreationForm
	, &Intern::createRobotomyRequestForm
	, &Intern::createPresidentialPardonForm
};

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {
}

AForm* Intern::makeForm(string name, string target) {
	for (int i = 0; i < AVAILABLE_FORMS_COUNT; i ++) {
		if (AVAILABLE_FORMS_NAMES[i] == name) {
			return ((this->*AVAILABLE_FORMS_CONSTRUCTORS[i])(target));
		}
	}
	cout << "No form named '" << name << "'" << endl;
	return (0);
}
