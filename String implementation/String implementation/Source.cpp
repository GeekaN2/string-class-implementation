#include <iostream>
#include <regex>
#include <cmath>
using namespace std;

// Do I need comments? You must be joking, lmao...

class String {
public:
	char* start;
	int length;
	String() {
		this->length = 0;
	};
	String(char s[]) {
		this->start = &s[0];
		for (this->length = 0; s[this->length] != '\0'; this->length++) {}
	};
	String(const char s[]) {
		this->length = strlen(s);
		char *nstr = new char[this->length + 1];
		strcpy_s(nstr, this->length + 1, &s[0]);
		this->start = &nstr[0];
	}
	String(char c) {
		this->length = 1;
		this->start = &c;
	};
	String(const String &s) {
		this->length = s.length;
		char *nstr = new char[s.length + 1]; // actually new useless string
		strcpy_s(nstr, s.length + 1, s.start);
		this->start = &nstr[0];
	}
	~String() {
		// you can write something here
	};

	char getChar(int i) {
		if (i >= 0 && i < this->length)
			return *(this->start + i);
		else
			return '\0';
	};

	char operator[] (int index) {
		return *(this->start + index);
	}

	bool operator > (String s) {
		for (int i = 0; i < min(this->length, s.length); i++) {
			if ((*this)[i] > s[i])
				return true;
			else if ((*this)[i] < s[i])
				return false;
		}
		if (this->length > s.length)
			return true;
	}

	bool operator < (String s) {
		return !(*this > s);
	}

private:

};

class StringId : public String {
public:
	StringId() : String() {}
	StringId(const StringId &s) : String(s) {}
	StringId(char s[]) {
		if (regex_match(s, regex("^[a-zA-Z_][a-zA-Z0-9_]*$"))) {
			this->start = &s[0];
			for (this->length = 0; s[this->length] != '\0'; this->length++) {}
		}
		else {
			assignEmptyString();
		}
	};
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
	~StringId() {
		// Destructor yeah
	}

	void toLowercase() {
		for (int i = 0; i < length; i++) {
			if (this->getChar(i) >= int('A') && this->getChar(i) <= int('Z')) {
				*(start + i) ^= 32; // PROSTYLE
			}
		}
	}


private:
	void assignEmptyString() {
		char *nstr = new char[1];
		strcpy_s(nstr, 1, "\0");
		this->start = &nstr[0];
		this->length = 0;
	}
};


int main() {
	char s[] = "test_string";
	StringId saske = StringId(s);
	StringId kek = "cool.string";
	bool ok = saske > kek;
	system("pause");
	return 0;
}