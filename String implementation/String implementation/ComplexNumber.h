#pragma once
#include <iostream>
#include <regex>
#include <cmath>
#include "String.h"

using namespace std;

class ComplexNumber {
public:

	// Real part of complex number
	long double real;

	// Imaginary part of complex number
	long double imaginary;

	// There are no parameters, then a zero
	ComplexNumber() {
		assignZeroNumber();
	}

	// Parse string for 2 parts - real and imaginary
	ComplexNumber(char s[]) {
		if (regex_match(s, regex("[+-]?\\d+.?\\d*i[+-]?\\d+.?\\d*"))) {
			int delimeterIndex = 0;
			for (int i = 0; i < strlen(s); i++) {
				if (s[i] == 'i') {
					delimeterIndex = i;
					break;
				}
			}
			this->real = String(s).slice(0, delimeterIndex).toInt();
			this->imaginary = String(s).slice(delimeterIndex + 1).toInt();
		}
		else {
			assignZeroNumber();
		}
	}

	// The exact same constructor
	ComplexNumber(const char s[]) {
		if (regex_match(s, regex("[+-]?\\d+.?\\d*i[+-]?\\d+.?\\d*"))) {
			int delimeterIndex = 0;
			for (int i = 0; i < strlen(s); i++) {
				if (s[i] == 'i') {
					delimeterIndex = i;
					break;
				}
			}
			this->real = String(s).slice(0, delimeterIndex).toInt();
			this->imaginary = String(s).slice(delimeterIndex + 1).toInt();
		}
		else {
			assignZeroNumber();
		}
	}

	// Copy constructor
	ComplexNumber(const ComplexNumber &n) {
		this->real = n.real;
		this->imaginary = n.imaginary;
	}

	ComplexNumber operator / (const ComplexNumber &n) {
		ComplexNumber ans = ComplexNumber();
		ans.real = (this->real * n.real + this->imaginary * n.imaginary) / (pow(n.real, 2) + pow(n.imaginary, 2));
		ans.imaginary = (n.real * this->imaginary - this->real * n.imaginary) / (pow(n.real, 2) + pow(n.imaginary, 2));
		return ans;
	}

	bool operator == (const ComplexNumber &n) {
		return this->real == n.real && this->imaginary == n.imaginary;
	}

private:

	// Zero
	void assignZeroNumber() {
		this->real = 0;
		this->imaginary = 0;
	}
};