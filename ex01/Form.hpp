#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

using std::string;
using std::exception;
using std::ostream;

class Form {
private:
	const string _name;
	static const string DEFAULT_NAME;
	static const int LOWEST_GRADE = 150;
	static const int HIGHEST_GRADE = 1;
	int _signGrade;
	static const int DEFAULT_SIGN_GRADE = HIGHEST_GRADE - 1;
	int _execGrade;
	static const int DEFAULT_EXEC_GRADE = HIGHEST_GRADE - 1;
	bool _isSigned;

	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	void setSignGrade(int grade);
	void setExecGrade(int grade);
	static void checkGradeLimits(int grade);

public:
	Form(const string &name, int signGrade, int execGrade);
	~Form();

	const string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public exception {
	public:
		const char *what() const throw();
	};
};

ostream &operator<<(ostream &os, const Form &b);
#endif
