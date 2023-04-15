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
void Word::printWordNameOnly()
{
	std::cout << name << std::endl;
}

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

// Predicate function identifying whether word is a palindrome, i.e. same spelt
// backwards or forwards. Function operates by splitting the word into two substrings:
// index 0 to middle letter (first half of word and index -1 to middle letter (second
// half of word spelt backwards) and comparing.
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

bool Word::guessFourthWordEligible()
{
	if (definition.length() > 20) // TODO: if definition has more than 4 words
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Setter/Getter implementation
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