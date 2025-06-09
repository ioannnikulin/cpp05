#include <cassert>
#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::stringstream;

static void shrubbery_test() {
	try {
		Bureaucrat a("Anna", 150);
		ShrubberyCreationForm f("somewhere");
		a.signForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Bureaucrat a("Arkadia", 145);
		ShrubberyCreationForm f("somewhere");
		a.signForm(f);
		a.executeForm(f);
	} catch (exception &e) {
		cout << e.what() << endl;
		assert(e.what() == string("Grade too low"));
	}
	try {
		Bureaucrat a("Abby", 100);
		ShrubberyCreationForm f("somewhere");
		a.executeForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Form not signed yet"));
	}
	{
		Bureaucrat a("Adele", 100);
		ShrubberyCreationForm f("somewhere");
		a.signForm(f);
		a.executeForm(f);
	}
}

static void robotomy_test() {
	try {
		Bureaucrat a("Anton", 150);
		RobotomyRequestForm f("somebody");
		a.signForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Bureaucrat a("Artem", 70);
		RobotomyRequestForm f("somebody");
		a.signForm(f);
		a.executeForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Bureaucrat a("Adam", 40);
		RobotomyRequestForm f("somebody");
		a.executeForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Form not signed yet"));
	}
	{
		Bureaucrat a("Alex", 40);
		RobotomyRequestForm f("somebody");
		a.signForm(f);
		a.executeForm(f);
	}
}

static void pardon_test() {
	try {
		Bureaucrat a("Aida", 30);
		PresidentialPardonForm f("Don Quixote");
		a.signForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Bureaucrat a("Athena", 20);
		PresidentialPardonForm f("Don Quixote");
		a.signForm(f);
		a.executeForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Bureaucrat a("Afrodite", 1);
		PresidentialPardonForm f("Don Quixote");
		a.executeForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Form not signed yet"));
	}
	{
		Bureaucrat a("Achilles", 1);
		PresidentialPardonForm f("Don Quixote");
		a.signForm(f);
		a.executeForm(f);
	}
}

int main() {
	srand(time(0));
	shrubbery_test();
	robotomy_test();
	pardon_test();
	return (0);
}
