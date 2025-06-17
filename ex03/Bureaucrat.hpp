#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::exception;
using std::ostream;

class AForm;

class Bureaucrat {
private:
	const string _name;
	static const string DEFAULT_NAME;
	int _grade;
	static const int LOWEST_GRADE = 150;
	static const int HIGHEST_GRADE = 1;
	static const int DEFAULT_GRADE = LOWEST_GRADE - 1;

	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	void setGrade(int grade);

public:
	Bureaucrat(const string &name, int grade);
	~Bureaucrat();

	const string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &f) const;
	void executeForm(AForm const &f) const;

	class GradeTooHighException : public exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public exception {
	public:
		const char *what() const throw();
	};
};

ostream &operator<<(ostream &os, const Bureaucrat &b);
#endif
