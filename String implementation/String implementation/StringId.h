#pragma once
#include <iostream>
#include <regex>
#include <cmath>
#include "String.h"

using namespace std;

class StringId : public String {
public:

	// Copying simple constructor from the String class
	StringId() : String() {}

	// Also copy the constructor
	StringId(const StringId &s) : String(s) {}

	// Constructor for an array of chars with checking for compliance with the template
	StringId(char s[]) {
		if (regex_match(s, regex("^[a-zA-Z_][a-zA-Z0-9_]*$"))) {
			this->start = &s[0];
			for (this->length = 0; s[this->length] != '\0'; this->length++) {}
		}
		else {
			assignEmptyString();
		}
	};

	// Specially for const char
	StringId(const char s[]) {
		if (regex_match(s, regex("^[a-zA-Z_][a-zA-Z0-9_]*$"))) {
			char *nstr = new char[strlen(s) + 1];
			strcpy_s(nstr, strlen(s) + 1, &s[0]);
			this->start = &nstr[0];
			for (this->length = 0; s[this->length] != '\0'; this->length++) {}
		}
		else {
			assignEmptyString();
		}
	};

	// Destructor
	~StringId() {
		// Destructor yeah
	}

	// Lower all letters to lower case
	void toLowercase() {
		for (int i = 0; i < length; i++) {
			if (this->getChar(i) >= int('A') && this->getChar(i) <= int('Z')) {
				*(start + i) ^= 32; // PROSTYLE
			}
		}
	}


private:

	// A bit of DRY
	// Assign empty string
	void assignEmptyString() {
		char *nstr = new char[1];
		strcpy_s(nstr, 1, "\0");
		this->start = &nstr[0];
		this->length = 0;
	}
};