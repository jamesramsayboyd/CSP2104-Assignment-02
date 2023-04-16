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
	size_t wordLength = wordToRhyme.length();
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
	const int MAX_SEARCHDLE_GUESSES = 6;
	bool gameRunning = true;
	bool answerFound = false;
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
			answerFound = false;
			while (!answerFound)
			{
				std::cout << "Number of possible answers: " << wordList.size() << std::endl;
				std::cout << "Enter number of letters: " << std::endl;
				int wordLength = checkForValidIntInput(10);
				trimSearchdleAnswerSize(wordLength);

				std::cout << "Number of possible answers: " << potentialSearchdleAnswers.size() << std::endl;

				for (int i = 0; i < MAX_SEARCHDLE_GUESSES; i++)
				{
					std::cout << "Guess #" << i + 1 << ":" << std::endl;
					inputSearchdleGuess(wordLength);
					std::cout << std::endl;
					if (potentialSearchdleAnswers.size() == 1)
					{
						std::cout << "Answer found!" << std::endl;
						potentialSearchdleAnswers[0].printWordNameOnly();
						answerFound = true;
						break;
					}
					else if (potentialSearchdleAnswers.size() == 0)
					{
						std::cout << "Sorry, could not find answer in dictionary" << std::endl;
						answerFound = true;
						break;
					}
				}
			}
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

void ExtendedDictionary::trimSearchdleAnswerSize(int wordLength)
{
	std::vector<Word> temp;
	for (int i = 0; i < wordList.size(); i++)
	{
		if (wordList[i].getName().length() == wordLength)
		{
			temp.push_back(wordList[i]);
		}
	}
	potentialSearchdleAnswers = temp;
}

void ExtendedDictionary::inputSearchdleGuess(int wordLength)
{
	int colourChoice = 0;
	char letterChoice = ' ';
	for (int i = 0; i < wordLength; i++)
	{
		std::cout << "Letter #" << i + 1 << ": " << std::endl;
		std::cout << "Colour:  1. Green  2. Yellow  3: Grey  (4: Exit)" << std::endl;
		colourChoice = checkForValidIntInput(4);
		std::cout << "Letter: " << std::endl;
		std::cin >> letterChoice;

		switch (colourChoice)
		{
		case 1:
		{
			/*for (int j = 0; j < potentialSearchdleAnswers.size(); j++)
			{
				std::vector<Word> temp;
				if (!potentialSearchdleAnswers[j].containsLetterAtIndex(letterChoice, i))
				{
					temp.push_back(potentialSearchdleAnswers[j]);
				}
				potentialSearchdleAnswers = temp;
			}*/
			for (int j = potentialSearchdleAnswers.size() - 1; j >= 0; j--)
			{
				if (!potentialSearchdleAnswers[j].containsLetterAtIndex(letterChoice, i))
				{
					potentialSearchdleAnswers.erase(potentialSearchdleAnswers.begin() + j);
				}
			}
			std::cout << "No. of potential answers: " << potentialSearchdleAnswers.size() << std::endl;
			break;
		}
		case 2:
		{
			for (int j = potentialSearchdleAnswers.size() - 1; j >= 0; j--)
			{
				if (!potentialSearchdleAnswers[j].containsLetter(letterChoice))
				{
					potentialSearchdleAnswers.erase(potentialSearchdleAnswers.begin() + j);
				}
			}
			std::cout << "No. of potential answers: " << potentialSearchdleAnswers.size() << std::endl;
			break;
		}
		case 3:
		{
			for (int j = potentialSearchdleAnswers.size() - 1; j >= 0; j--)
			{
				if (potentialSearchdleAnswers[j].containsLetter(letterChoice))
				{
					potentialSearchdleAnswers.erase(potentialSearchdleAnswers.begin() + j);
				}
			}
			std::cout << "No. of potential answers: " << potentialSearchdleAnswers.size() << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "Returning to previous menu" << std::endl;
			return;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void ExtendedDictionary::printSearchdleAnswer()
{
	std::cout << "Answer found!" << std::endl;
	potentialSearchdleAnswers[0].printWordNameOnly();
}

int ExtendedDictionary::getGuessTheFourthWordHighScore()
{
	return guessTheFourthWordHighScore;
}

void ExtendedDictionary::setGuessTheFourthWordHighScore(int scoreToSet)
{
	guessTheFourthWordHighScore = scoreToSet;
}
