#pragma once

#include <string>

/* James Boyd, Student ID: 10629572, 13/4/2023
A class storing the details of a word from a dictionary file provided by the
user. The class has three properties, all of type String: name, type and definition.
There are no methods. */
//struct Word
//{
//	std::string name, type, definition;
//};

// Declaration section
class Word
{
	// Properties
private:
	std::string name, type, definition;

	// Method declaration
public:
	Word(); // Default Constructor
	Word(std::string, std::string, std::string); // Overloaded Constructor
	void printWordNameOnly();
	void printDefinition();
	bool isPalindrome();
	bool guessFourthWordEligible();

	// Setter/Getter method declaration
	std::string getName();
	void setName(std::string);
	std::string getType();
	void setType(std::string);
	std::string getDefinition();
	void setDefinition(std::string);
};