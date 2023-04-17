#pragma once

#include <string>

// Declaration section
class Word
{
	// Properties
private:
	std::string name, type, definition;
	bool validSearchdleAnswer = true;

	// Method declaration
public:
	Word(); // Default Constructor
	Word(std::string, std::string, std::string); // Overloaded Constructor
	void printWordNameOnly();
	void printDefinition();
	void printDefinitionMinusFourthWord();
	bool isPalindrome();
	bool guessFourthWordEligible();
	bool containsLetter(char);
	bool containsLetterAtIndex(char, int);


	// Setter/Getter method declaration
	std::string getName();
	void setName(std::string);
	std::string getType();
	void setType(std::string);
	std::string getDefinition();
	void setDefinition(std::string);
	std::string getLastThreeLetters();
	std::string getFourthWordOfDefinition();
	bool getValidSearchdleAnswer();
	void setValidSearchdleAnswer(bool);
};