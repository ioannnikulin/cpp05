#include <cassert>
#include <iostream>
#include <sstream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::stringstream;

int main() {
	{
		Bureaucrat d("Donald", 1);
		Form f("Tariffs", 1, 120);
		assert(false == f.isSigned());
		d.signForm(f);
		assert(true == f.isSigned());
	}
	try {
		Bureaucrat e("Elon", 50);
		Form f("Tariffs", 1, 120);
		assert(false == f.isSigned());
		e.signForm(f);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Form e("Exterminatus", 0, 5);
	} catch (exception &e) {
		assert(e.what() == string("Grade too high"));
	}
	try {
		Form s("Unicorn Sandwich", 150, 0);
	} catch (exception &e) {
		assert(e.what() == string("Grade too high"));
	}
	try {
		Form e("Existence", 151, 150);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
	try {
		Form e("Existence", 150, 151);
	} catch (exception &e) {
		assert(e.what() == string("Grade too low"));
	}
}
