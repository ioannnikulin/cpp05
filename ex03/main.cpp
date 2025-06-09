#include <cassert>
#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::stringstream;

int main() {
	srand(time(0));
	Intern someRandomIntern;
	AForm *rrf;
	Bureaucrat b("Bobby", 1);
	rrf = someRandomIntern.makeForm("doesnt exist", "nobody");
	assert(rrf == 0);
	rrf = someRandomIntern.makeForm("shrubbery creation", "Alex");
	assert(rrf->getName() == "Shrubbery Creation Form");
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Baldwin");
	assert(rrf->getName() == "Robotomy Request Form");
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Cirilla");
	assert(rrf->getName() == "Presidential Pardon Form");
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;
	return (0);
}
