#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "Bureaucrat.hpp"

using std::string;
using std::exception;
using std::ostream;

class Intern {
private:
	typedef AForm* (Intern::*FormCreator)(const string &target);

	static const int AVAILABLE_FORMS_COUNT = 3;
	static const string AVAILABLE_FORMS_NAMES[AVAILABLE_FORMS_COUNT];
	static const FormCreator AVAILABLE_FORMS_CONSTRUCTORS[AVAILABLE_FORMS_COUNT];

	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm* createShrubberyCreationForm(const string &target);
	AForm* createRobotomyRequestForm(const string &target);
	AForm* createPresidentialPardonForm(const string &target);

public:
	Intern();
	~Intern();

	AForm *makeForm(string name, string target);
};
#endif