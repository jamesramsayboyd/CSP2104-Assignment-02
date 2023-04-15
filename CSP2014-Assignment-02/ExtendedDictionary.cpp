#include <string>
#include <random>
#include <vector>
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
			std::cout << std::endl;
		}
	}
	if (palindromeCounter < 1)
	{
		std::cout << "ERROR: No palindromes found" << std::endl;
	}
	else
	{
		std::cout << palindromeCounter << " palindrome(s) found" << std::endl;
	}
}

void ExtendedDictionary::findRhymingWords(std::string wordToRhyme)
{
	std::cout << "Displaying all words that rhyme with \"" << wordToRhyme << "\":" << std::endl;
	int wordLength = wordToRhyme.length();
	std::string rhymeTarget = "";
	if (wordLength < 3)
	{
		rhymeTarget = wordToRhyme;
	}
	else
	{
		int threeFromLast = wordToRhyme.length() - 3;
		rhymeTarget = wordToRhyme.substr(wordLength - 3, wordLength); // finding last three letters of target word
	}
	int rhymeCounter = 0;
	for (Word word : this->wordList)
	{
		if (word.getLastThreeLetters() == rhymeTarget)
		{
			rhymeCounter++;
			word.printDefinition();
			std::cout << std::endl;
		}
	}
	if (rhymeCounter < 1)
	{
		std::cout << "ERROR: No rhyming words found" << std::endl;
	}
	else
	{
		std::cout << rhymeCounter << " rhyming word(s) found" << std::endl;
	}
}

void ExtendedDictionary::playGuessTheFourthWord()
{
	int score = 0;	
	bool gameRunning = true;
	std::cout << "Welcome to Guess The Fourth Word!" << std::endl;

	while (gameRunning)
	{
		std::cout << "Current High Score: " << guessTheFourthWordHighScore << std::endl;
		std::cout << "Press 1 to play a new game" << std::endl;
		std::cout << "Press 2 to view instructions" << std::endl;
		std::cout << "Press 3 to exit the game" << std::endl;

		int userChoice = checkForValidIntInput(3);

		switch (userChoice)
		{
		case 1:
		{
			while (true) 
			{
				int eligibleIndex = 0;
				while (true)
				{
					int random = generateRandomNumber(wordList.size());
					if (wordList[random].guessFourthWordEligible())
					{
						eligibleIndex = random;
						break;
					}
				}
				Word wordToPlay = wordList[eligibleIndex];
				std::string fourthWord = wordToPlay.getFourthWordOfDefinition();
				std::cout << "Word: " << wordToPlay.getName() << std::endl;
				wordToPlay.printDefinitionMinusFourthWord();
				std::cout << "\nGuess The Fourth Word!" << std::endl;
				std::string userGuess;
				std::cin >> userGuess;

				if (userGuess == fourthWord)
				{
					std::cout << "Correct!\n10 points awarded, beginning new game:\n" << std::endl;
					score += 10;
					if (score > getGuessTheFourthWordHighScore())
					{
						std::cout << "*** You have set the new high score! ***\n" << std::endl;
						setGuessTheFourthWordHighScore(score);
					}
				}
				else
				{
					std::cout << "\nIncorrect!\nYour score was: " << score << "\nReturning to menu\n" << std::endl;
					gameRunning = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			std::cout << "A word will be randomly selected from the dictionary. Guess the fourth word of the\n"
				"definition correctly to earn 10 points. An incorrect guess will end the game.\n" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Returning to menu\n" << std::endl;
			gameRunning = false;
			break;
		}
		default:
			break;
		}
	}
	
}

void ExtendedDictionary::cheatAtSearchdle()
{
	std::vector<Word> possibleAnswers = wordList;
	bool gameRunning = true;
	std::cout << "Cheat at Searchdle" << std::endl;

	while (gameRunning)
	{
		std::cout << "Press 1 to find the current word" << std::endl;
		std::cout << "Press 2 to view Searchdle instructions" << std::endl;
		std::cout << "Press 3 to exit the game" << std::endl;

		int userChoice = checkForValidIntInput(3);

		switch (userChoice)
		{
		case 1:
		{
			std::cout << "Number of words: " << possibleAnswers.size() << std::endl;
			std::cout << "Enter all grey letters" << std::endl;
			std::cin >> greyLetters;

			/*for (int i = 0; i < possibleAnswers.size(); i++)
			{
				for (int j = 0; j < greyLetters.length(); j++)
				{
					if (!possibleAnswers[i].containsSpecificLetter(greyLetters[j]))
					{
						possibleAnswers.erase(possibleAnswers.begin() + i);
					}
				}
			}*/

			for (int i = 0; i < greyLetters.length(); i++)
			{
				for (int j = 0; j < possibleAnswers.size(); j++)
				{
					if (!possibleAnswers[j].containsSpecificLetter(greyLetters[i]))
					{
						possibleAnswers.erase(possibleAnswers.begin() + j);
					}
				}
			}
			std::cout << "Number of words: " << possibleAnswers.size() << std::endl;

			std::cout << "Enter all yellow letters" << std::endl;
			std::cin >> yellowLetters;

			for (int i = 0; i < possibleAnswers.size(); i++)
			{
				for (char x : yellowLetters)
				{
					if (!possibleAnswers[i].containsSpecificLetter(x))
					{
						possibleAnswers.erase(possibleAnswers.begin() + i);
					}
				}
			}
			std::cout << "Number of words: " << possibleAnswers.size() << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "Searchdle gives you six chances to guess a randomly generated word. etc etc" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Returning to menu\n" << std::endl;
			gameRunning = false;
			break;
		}
		default:
			break;
		}
	}

}

int ExtendedDictionary::getGuessTheFourthWordHighScore()
{
	return guessTheFourthWordHighScore;
}

void ExtendedDictionary::setGuessTheFourthWordHighScore(int scoreToSet)
{
	guessTheFourthWordHighScore = scoreToSet;
}
