#include <iostream>
#include <regex>
#include <cmath>
#include "String.h"
#include "StringId.h"
#include "ComplexNumber.h"

using namespace std;

int main() {
	char test_string[] = "test_string";
	String simple_string = String(test_string);
	StringId cool_id = StringId(test_string);
	StringId id = "cool.string";
	bool greater_then = cool_id > id;

	char str_0[] = "-192i20";
	ComplexNumber complex_number = ComplexNumber(str_0);
	ComplexNumber complex_number_copy = complex_number;

	char str_1[] = "-2i1";
	char str_2[] = "1i-1";
	ComplexNumber complex_n1 = ComplexNumber(str_1);
	ComplexNumber complex_n2 = ComplexNumber(str_2);
	complex_n1 = complex_n1 / complex_n2;

	system("pause");
	return 0;
}