#include <string>
#include "ExtendedDictionary.h"

void ExtendedDictionary::displayPalindromes()
{
	std::cout << "Displaying all palindromes:" << std::endl;
	int palindromeCounter = 0;
	for (Word word : wordList)
	{
		if (word.isPalindrome())
		{
			palindromeCounter++;
			word.printDefinition();
		}
	}
	if (palindromeCounter < 1)
	{
		std::cout << "ERROR: No palindromes found" << std::endl;
	}
}

void ExtendedDictionary::findRhymingWords(std::string wordToRhyme)
{
	std::string rhymeTarget = wordToRhyme.substr(-4, -1);
	for (Word word : this->wordList)
	{
		if (word.getName().substr(-4, -1) == rhymeTarget)
		{
			word.printDefinition();
		}
	}
}

void ExtendedDictionary::playGuessTheFourthWord()
{

}

void ExtendedDictionary::cheatAtSearchdle()
{

}
