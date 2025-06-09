#include <fstream>

#include "ShrubberyCreationForm.hpp"

using std::ofstream;
using std::endl;

const string ShrubberyCreationForm::FORM_NAME = "Shrubbery Creation Form";
const string ShrubberyCreationForm::DEFAULT_TARGET = "nowhere";
const string ShrubberyCreationForm::SHRUBBERY =
"            v .   ._, |_  .,           \n\
           `-._\\/  .  \\ /    |/_    \n\
               \\\\  _\\, y | \\//      \n\
         _\\_.___\\\\, \\\\/ -.\\||       \n\
           `7-,--.`._||  / / ,       \n\
           /'     `-. `./ / |/_.'    \n\
                     |    |//        \n\
                     |_    /         \n\
                     |-   |          \n\
                     |   =|          \n\
                     |    |          \n\
--------------------/ ,  . \\--------.\n";

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE)
	, _target(DEFAULT_TARGET)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
	, _target(other._target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target):
	AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE)
	, _target(target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other) {
		return (*this);
	}
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const {
	AForm::preexecutionCheck(b);
	string fname = _target + "_shrubbery";
	ofstream f(fname.c_str());
	f << SHRUBBERY << endl;
	f.close();
}