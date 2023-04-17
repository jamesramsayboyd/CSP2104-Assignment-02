#include <string>
#include <random>
#include <vector>
#include "ExtendedDictionary.h"


/* James Boyd, Student ID: 10629572, 15/04/2023
* Loops through the vector<Word> finding all Words where Word.isPalindrome() == true
* Prints full Word details when found
*/
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


/* James Boyd, Student ID: 10629572, 13/04/2023
* Prompts the user to enter a word, then searches for all words where the last three letters match
* the target word. Displays each word's name property only, as this function generally returns a lot
* of matches and printing full word details would take too much space
*/
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
			std::cout << word.getName() << ", ";
			if (rhymeCounter % 10 == 0)
			{
				std::cout << std::endl;
			}
		}
	}
	std::cout << std::endl;
	if (rhymeCounter < 1)
	{
		std::cout << "ERROR: No rhyming words found" << std::endl;
	}
	else
	{
		std::cout << rhymeCounter << " rhyming word(s) found" << std::endl;
	}
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* Initiates the 'Guess The Fourth Word' game. Generates a random number to choose a random word from the
* dictionary where the definition property has more than four words. The word's name and definition
* properties are displayed, with the fourth word of the definition replaced with underscores. The user is
* prompted to guess the fourth word. If their guess is correct, they earn 10 points and the game begins again.
* If they guess wrong, the game ends and the program returns to the main menu. The highest score is saved as
* a property of the ExtendedDictionary class and updated when a player beats the score
*/
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
					std::cout << "\nIncorrect! Answer was \"" << fourthWord << "\"\nYour score was: " << score << "\nReturning to menu\n" << std::endl;
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
			std::cout << "Returning to menu" << std::endl;
			gameRunning = false;
			break;
		}
		default:
			break;
		}
	}
	
}


#pragma region SEARCHDLE FUNCTIONS

/* James Boyd, Student ID: 10629572, 13/04/2023
* Initiates the 'Cheat At Searchdle' operation. User is first prompted to enter the number of letters in the
* target word. User must make their first guess in the external Searchdle game, then input their results here 
* letter by letter, specifying the colour of each letter. The program narrows down the pool of possible answers
* with each new letter, from the full size of the dictionary down to one single word. User can view a set of
* instructions if needed, both on how to play Searchdle and how to use this program.
* 
* DISCLAIMER: This function is not 100% effective. I've found that the Searchdle game uses a very different
* dictionary to what is provided in the dictionary_2023S1.txt file, so often the target word in Searchdle simply
* isn't present in this program's dictionary
*/
void ExtendedDictionary::cheatAtSearchdle()
{
	startOfSearchdleGame:
	searchdleRunning = true;
	answerFound = false;
	const int MAX_SEARCHDLE_GUESSES = 6;
	std::cout << "Cheat at Searchdle" << std::endl;

	while (searchdleRunning)
	{
		std::cout << std::endl;
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
				trimSearchdleAnswerPool(wordLength);

				std::cout << "Number of possible answers: " << potentialSearchdleAnswers.size() << std::endl;

				for (int i = 0; i < MAX_SEARCHDLE_GUESSES; i++)
				{
					std::cout << "Guess #" << i + 1 << ":" << std::endl;
					inputSearchdleGuess(wordLength);
					std::cout << std::endl;
					bool running = true;
					while (running)
					{
						std::cout << "1. Continue guessing  2. Ask for a hint  3. Exit" << std::endl;
						int userChoice = checkForValidIntInput(3);
						switch (userChoice)
						{
						case 1:
						{
							running = false;
							break;
						}
						case 2:
						{
							int index = generateRandomNumber(potentialSearchdleAnswers.size());
							std::cout << "Try \"" << potentialSearchdleAnswers[index].getName() << "\"" << std::endl;
							break;
						}
						case 3:
							std::cout << "Returning to menu" << std::endl;
							running = false;
							answerFound = true;
							searchdleRunning = false;
							break;
						}
					}
				}
			}
			break;
		}
		case 2:
		{
			std::cout << "Searchdle gives you six chances to guess a randomly generated word. When you enter a word as\n"
				"a guess, each letter in the word will be highlighted in a colour: Grey means that letter is\n"
				"not in the target word, Yellow means the letter is present in the target word but in a different\n"
				"position, and Green means you've guessed a letter and position correctly. To use this program,\n"
				"make your first guess in Searchdle and then input your results here when prompted, entering each\n"
				"letter and its colour using the numbered option menus. The program will narrow down the list of\n"
				"possible options with each letter entered until only one word remains: the target word!\n\n"
				"After each full word you can ask for a hint, in which case a word will be randomly selected from\n"
				"the list of possible answers for you to enter as your next guess." << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Returning to menu" << std::endl;
			searchdleRunning = false;
			break;
		}
		default:
			break;
		}
	}
}


/* James Boyd, Student ID: 10629572, 15/04/2023
* User is prompted to enter the length of the Searchdle target word, and this is used to trim down the
* pool of potential answers from the full size of the dictionary to only those words with the correct
* length. I initially implemented this method by looping through the vector<Word> and using the built-in
* vector.erase() function to delete non-matching words, but this operation was extremely inefficient. I
* refactored the method to instead *add* all matching words to a temporary vector<Word>, and then assign
* this vector<Word> to the original vector<Word> to discard all non-matching words
*/
void ExtendedDictionary::trimSearchdleAnswerPool(int wordLength)
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


/* James Boyd, Student ID: 10629572, 16/04/2023
* User is prompted to enter each letter of their Searchdle guess, one by one, specifying the colour
* of each letter. I have implemented the three conditions as follows:
* - Grey letters mean that all words in the dictionary containing that letter should be discarded
* - Yellow letters mean that all words with that letter in that specific position should be discarded
* - Green letters mean that all words with that letter in that specific position should be kept
*/
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
			std::vector<Word> temp;
			for (int j = 0; j < potentialSearchdleAnswers.size(); j++)
			{
				if (potentialSearchdleAnswers[j].containsLetterAtIndex(letterChoice, i))
				{
					temp.push_back(potentialSearchdleAnswers[j]);
				}
			}
			potentialSearchdleAnswers = temp;
			checkSearchdleAnswer();
			break;
		}
		case 2:
		{
			std::vector<Word> temp;
			for (int j = 0; j < potentialSearchdleAnswers.size(); j++)
			{
				if (!potentialSearchdleAnswers[j].containsLetterAtIndex(letterChoice, i))
				{
					temp.push_back(potentialSearchdleAnswers[j]);
				}
			}
			potentialSearchdleAnswers = temp;
			checkSearchdleAnswer();
			break;
		}
		case 3:
		{
			std::vector<Word> temp;
			for (int j = 0; j < potentialSearchdleAnswers.size(); j++)
			{
				if (!potentialSearchdleAnswers[j].containsLetter(letterChoice))
				{
					temp.push_back(potentialSearchdleAnswers[j]);
				}
			}
			potentialSearchdleAnswers = temp;
			checkSearchdleAnswer();
			break;
		}
		case 4:
		{
			std::cout << "Returning to previous menu" << std::endl;
			answerFound = true;
			searchdleRunning = false;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

/* James Boyd, Student ID: 10629572, 16/04/2023
* Checks whether the answer has been found (i.e. 1 potential word) or cannot be found (i.e. 0 potential
* words). If answer is found, user is informed and current game ends
*/
void ExtendedDictionary::checkSearchdleAnswer()
{
	if (potentialSearchdleAnswers.size() == 1)
	{
		std::cout << "Answer found!" << std::endl;
		potentialSearchdleAnswers[0].printWordNameOnly();
		answerFound = true;
		return;
	}
	else if (potentialSearchdleAnswers.size() == 0)
	{
		std::cout << "Sorry, answer does not exist in this dictionary" << std::endl;
		searchdleRunning = false;
		return;
	}
	std::cout << "No. of potential answers: " << potentialSearchdleAnswers.size() << std::endl;
}
#pragma endregion SEARCHDLE FUNCTIONS


#pragma region SETTERS AND GETTERS

int ExtendedDictionary::getGuessTheFourthWordHighScore()
{
	return guessTheFourthWordHighScore;
}

void ExtendedDictionary::setGuessTheFourthWordHighScore(int scoreToSet)
{
	guessTheFourthWordHighScore = scoreToSet;
}

bool ExtendedDictionary::getSearchdleRunning()
{
	return searchdleRunning;
}

void ExtendedDictionary::setSearchdleRunning(bool boolean)
{
	searchdleRunning = boolean;
}

bool ExtendedDictionary::getAnswerFound()
{
	return answerFound;
}

void ExtendedDictionary::setAnswerFound(bool boolean)
{
	answerFound = boolean;
}

#pragma endregion SETTERS AND GETTERS


