#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

using std::string;
using std::exception;
using std::ostream;

class AForm {
private:
	const string _name;
	static const string DEFAULT_NAME;
	int _signGrade;
	int _execGrade;
	bool _isSigned;
	static const int LOWEST_GRADE = 150;
	static const int HIGHEST_GRADE = 1;
	static const int DEFAULT_SIGN_GRADE = HIGHEST_GRADE - 1;
	static const int DEFAULT_EXEC_GRADE = HIGHEST_GRADE - 1;

	AForm();
	AForm(const AForm &other);
	void setSignGrade(int grade);
	void setExecGrade(int grade);
	static void checkGradeLimits(int grade);

protected:
	AForm(const string &name, int signGrade, int execGrade);
	AForm &operator=(const AForm &other);
	void preexecutionCheck(const Bureaucrat &b) const;

public:
	virtual ~AForm();

	const string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &b);

	virtual void execute(const Bureaucrat &b) const = 0;

	class GradeTooHighException : public exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public exception {
	public:
		const char *what() const throw();
	};

	class NoSignatureException : public exception {
	public:
		const char *what() const throw();
	};
};

ostream &operator<<(ostream &os, const AForm &b);
#endif