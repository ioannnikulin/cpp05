#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

#include "AForm.hpp"

using std::string;
using std::exception;
using std::ostream;

class ShrubberyCreationForm: public AForm {
private:
	static const string FORM_NAME;
	static const string DEFAULT_TARGET;
	static const string SHRUBBERY;
	static const int SIGN_GRADE = 145;
	static const int EXEC_GRADE = 137;
	string _target;

	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

public:
	ShrubberyCreationForm(const string &target);
	~ShrubberyCreationForm();

	virtual void execute(const Bureaucrat &b) const;
};
#endif
