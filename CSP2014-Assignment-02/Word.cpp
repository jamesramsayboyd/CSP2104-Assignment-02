#include "Word.h"
#include <iostream>

// Constructors
Word::Word() {}

Word::Word(std::string nameToSet, std::string typeToSet, std::string definitionToSet)
{
	this->name = nameToSet;
	this->type = typeToSet;
	this->definition = definitionToSet;
}

// Method implementation
/* James Boyd, Student ID: 10629572, 11/04/2023
* Prints only the name property of the Word
*/
void Word::printWordNameOnly()
{
	std::cout << name << std::endl;
}


/* James Boyd, Student ID: 10629572, 11/04/2023
* Prints name, type and definition properties of a Word. Type is formatted as specified in the
* assignment document (i.e. [noun], [verb], etc)
*/
void Word::printDefinition()
{
	std::cout << "Word: " << name << std::endl;
	std::cout << "Type: ";
	if (type == "n")
	{
		std::cout << "[noun]" << std::endl;
	}
	else if (type == "v")
	{
		std::cout << "[verb]" << std::endl;
	}
	else if (type == "adv")
	{
		std::cout << "[adverb]" << std::endl;
	}
	else if (type == "adj")
	{
		std::cout << "[adjective]" << std::endl;
	}
	else if (type == "prep")
	{
		std::cout << "[preposition]" << std::endl;
	}
	else if (type == "misc")
	{
		std::cout << "[miscellaneous]" << std::endl;
	}
	else if (type == "pn")
	{
		std::cout << "[proper noun]" << std::endl;
	}
	else if (type == "n_and_v")
	{
		std::cout << "[noun and verb]" << std::endl;
	}
	else
	{
		std::cout << "[unknown]" << std::endl;
	}
	std::cout << "Definition: " << definition << std::endl;
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* Prints a Word's definition property with the fourth word replaced with underscores. This
* function is used in the 'Guess The Fourth Word' game that runs within the program
*/
void Word::printDefinitionMinusFourthWord()
{
	int spaceCounter = 0;
	int fourthWordStartIndex = 0;
	int fourthWordEndIndex = 0;
	for (int i = 0; i < definition.length(); i++)
	{
		if (definition[i] == ' ')
		{
			spaceCounter++;
			i++;
		}
		if (spaceCounter > 2 && spaceCounter < 4)
		{
			definition[i] = '_';
		}
	}
	std::cout << definition << std::endl;
}


/* James Boyd, Student ID: 10629572, 17/04/2023
* Predicate function identifying whether word is a palindrome, i.e. same spelt
* backwards or forwards. Function operates by splitting the word into two substrings:
* index 0 to middle letter (first half of word and index -1 to middle letter (second
* half of word spelt backwards) and comparing
*/
bool Word::isPalindrome()
{
	int midpoint = name.length() / 2;
	std::string firstHalf = name.substr(0, midpoint);
	std::string secondHalf = name.substr(midpoint, name.length() + 1);
	std::reverse(secondHalf.begin(), secondHalf.end());

	if (firstHalf == secondHalf)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* Predicate function identifying whether the name property of a Word contains a certain
* letter, provided as an argument. This is used in the 'Cheat At Searchdle' option of the
* main program
*/
bool Word::containsLetter(char targetLetter)
{
	for (char x : name)
	{
		if (x == targetLetter)
		{
			return true;
		}
	}
	return false;
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* Predicate function identifying whether the name property of a Word contains a certain
* letter at a certain index, both provided as arguments. This is used in the 'Cheat At 
* Searchdle' option of the main program
*/
bool Word::containsLetterAtIndex(char targetLetter, int index)
{
	if (name[index] == targetLetter)
	{
		return true;
	}
	return false;
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* Predicate function identifying whether the Word is eligible for the 'Guess The Fourth
* Word' game, i.e. whether the dictionary property has at least four words
*/
bool Word::guessFourthWordEligible()
{
	int spaceCounter = 0;
	for (char x : definition)
	{
		if (x == ' ')
		{
			spaceCounter++;
		}
		if (spaceCounter > 3)
		{
			return true;
		}
	}
	return false;
}


#pragma region SETTERS AND GETTERS
/* James Boyd, Student ID: 10629572, 15/04/2023
* Setters and getters (self explanatory)
*/
std::string Word::getName()
{
	return name;
}

void Word::setName(std::string nameToSet)
{
	this->name = nameToSet;
}

std::string Word::getType()
{
	return type;
}

void Word::setType(std::string typeToSet)
{
	this->type = typeToSet;
}

std::string Word::getDefinition()
{
	return definition;
}

void Word::setDefinition(std::string definitionToSet)
{
	this->definition = definitionToSet;
}

bool Word::getValidSearchdleAnswer()
{
	return validSearchdleAnswer;
}

void Word::setValidSearchdleAnswer(bool boolean)
{
	validSearchdleAnswer = boolean;
}

/* James Boyd, Student ID: 10629572, 15/04/2023
* Gets the last three letters of a Word's name property. This is used in the 'Find Rhyming Words'
* operation in the main program
*/
std::string Word::getLastThreeLetters()
{
	std::string name = this->getName();
	int wordLength = name.length();
	if (wordLength < 3)
	{
		return this->name;
	}
	else
	{
		int threeFromLast = name.length() - 3;
		std::string lastThreeLetters = name.substr(threeFromLast, wordLength);
		return lastThreeLetters;
	}
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* Gets the fourth word of a Word's definition property. This is used in the 'Guess The Fourth
* Word' game in the main program
*/
std::string Word::getFourthWordOfDefinition()
{
	int spaceCounter = 0;
	int fourthWordStartIndex = 0;
	int fourthWordEndIndex = 0;
	int wordLength = 0;
	std::string fourthWord = "";

	for (int i = 0; i < definition.length(); i++)
	{
		if (definition[i] == ' ')
		{
			spaceCounter++;
		}
		if (spaceCounter == 3)
		{
			fourthWordStartIndex = i + 1;
			spaceCounter++;
		}
		if (spaceCounter == 5)
		{
			fourthWordEndIndex = i;
			wordLength = fourthWordEndIndex - fourthWordStartIndex;
			fourthWord = definition.substr(fourthWordStartIndex, wordLength);
			return fourthWord;
		}
	}
}

#pragma endregion SETTERS AND GETTERS