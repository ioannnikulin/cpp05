#include <cassert>
#include <iostream>
#include <sstream>

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::stringstream;

int main() {
	try {
		Bureaucrat a("Anna", 1);
		stringstream ss;
		ss << a;
		assert(ss.str() == "Anna, bureaucrat grade 1");
		assert("Anna" == a.getName());
		assert(1 == a.getGrade());
		a.incrementGrade();
	} catch (exception &e) {
		assert(e.what() == string("Grade too high"));
	}
	try {
		Bureaucrat a("Anna", 150);
		a.incrementGrade();
		assert(a.getGrade() == 149);
		a.decrementGrade();
		assert(a.getGrade() == 150);
		a.decrementGrade();
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	return (0);
}
