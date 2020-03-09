#include <iostream>
#include <regex>
#include <cmath>
using namespace std;

// Do I need comments? You must be joking, lmao...

class String {
public:
	
	// Position of the first character
	char* start;

	// Length of full string
	int length;

	// Simple constructor for an empty string
	String() {
		this->length = 0;
	};

	// Constructor for an array of chars
	String(char s[]) {
		this->start = &s[0];
		for (this->length = 0; s[this->length] != '\0'; this->length++) {}
	};

	// Special constructor so that you can set 
	// strings of the form like this
	// String cool_name = "Hello, bar!";
	String(const char s[]) {
		this->length = strlen(s);
		char *nstr = new char[this->length + 1];
		strcpy_s(nstr, this->length + 1, &s[0]);
		this->start = &nstr[0];
	}

	// Constructor for one char
	String(char c) {
		this->length = 1;
		this->start = &c;
	};

	// Copy constructor
	String(const String &s) {
		this->length = s.length;
		char *nstr = new char[s.length + 1]; // a few conversions to a regular char
		strcpy_s(nstr, s.length + 1, s.start);
		this->start = &nstr[0];
	}

	// Destructor
	~String() {
		// I don't need to write anything here
		// he will clean everything himself
	};

	// Returns a character at the position of this string or '\0'
	char getChar(int i) {
		if (i >= 0 && i < this->length) {
			return *(this->start + i);
		}
		else {
			return '\0';
		}
	};

	// Definig an indexing operator
	char operator[] (int index) {
		return getChar(index);
	}

	// Definig '>' operator 
	bool operator > (String s) {
		for (int i = 0; i < min(this->length, s.length); i++) {
			if ((*this)[i] > s[i]) {
				return true;
			}
			else if ((*this)[i] < s[i]) {
				return false;
			}
		}
		if (this->length > s.length) {
			return true;
		}
	}

	// Definig '<' operator as the negation of '>'
	bool operator < (String s) {
		return !(*this > s);
	}

	// Cut string to [start, end)
	String slice(int start, int end = -1) {
		if (start >= end && end != -1) {
			return String("");
		}
		if (end > this->length || end == -1) {
			end = this->length;
		}
		char *nstr = new char[end - start + 1];
		for (int i = start; i < end; i++) {
			nstr[i - start] = (*this)[i];
		}
		nstr[end] = '\0';
		return String(nstr);
	}

	// Normal strings addition
	String operator + (String s) {;
		char *nstr = new char[s.length + this->length + 1];
		for (int i = 0; i < this->length; i++) {
			nstr[i] = (*this)[i];
		}
		for (int i = this->length; i < this->length + s.length; i++) {
			nstr[i] = s[i - this->length];
		}
		nstr[this->length + s.length] = '\0';
		return String(nstr);
	}

	// Short addition record
	void operator += (String s) {
		*this = (*this + s);
	}

	// Just the stoi function
	int toInt() {
		try {
			return stoi(this->start);
		}
		catch (...) {
			return 0;
		}
	}

private:
	// Waiting for something interesting
};

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

class ComplexNumber {
public:

	// Real part of complex number
	long long real;

	// Imaginary part of complex number
	long long imaginary;

	// There are no parameters, then a zero
	ComplexNumber() {
		assignZeroNumber();
	}

	// Parse string for 2 parts - real and imaginary
	ComplexNumber(char s[]) {
		if (regex_match(s, regex("[+-]?[0-9]+i[+-]?[0-9]+"))) {
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

private:

	// Zero
	void assignZeroNumber() {
		this->real = 0;
		this->imaginary = 0;
	}
};

int main() {
	/** 
	 * Test for String and StringId
	 *
	 * char s[] = "test_string";
	 * StringId cool_name = StringId(s);
	 * StringId not_so = "cool.string";
	 * bool ok = cool_name > not_so;
	 */

	char s[] = "-192i20";
	ComplexNumber cool_name = ComplexNumber(s);

	system("pause");
	return 0;
}