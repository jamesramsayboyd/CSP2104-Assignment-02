#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "Word.h"
#include "Dictionary.h"
#include "ExtendedDictionary.h"
//#include "Utilities.h"

using namespace std;

int main()
{
	ExtendedDictionary dictionary = ExtendedDictionary();
	bool running = true; // A boolean tracking whether the program is running, updated to false when the user chooses to exit
	bool fileLoaded = false; // A boolean tracking whether a .txt file has been loaded
	int userInput = 0;
	const string DEFAULT_DICTIONARY_NAME = "dictionary_2023S1.txt"; // The .txt file provided for the assignment

	cout << "Welcome to the Dictionary" << endl;

	while (running)
	{
		if (!fileLoaded)
		{
			const int MENU_SIZE = 3; // Three choices in this menu
			cout << endl;
			cout << "Press 1 to load the default Dictionary file" << endl;
			cout << "Press 2 to enter a specified Dictionary filename" << endl;
			cout << "Press 3 to exit" << endl;
			cout << endl;

			userInput = checkForValidIntInput(MENU_SIZE);

			switch (userInput)
			{
			case 1: // Load default dictionary .txt file into vector<Word> data structure
			{
				if (dictionary.loadFromFile(DEFAULT_DICTIONARY_NAME))
				{
					fileLoaded = true;
					cout << "File loaded successfully" << endl;
				}
				break;
			}
			case 2: // Load a user-specified .txt file into vector<Word> data structure
			{
				string filename;
				cout << "Enter filename: " << endl;
				cin >> filename;
				if (!dictionary.loadFromFile(filename))
				{
					cout << "ERROR: File not found" << endl;
				}
				else
				{
					fileLoaded = true;
					cout << "File loaded successfully" << endl;
				}
				break;
			}
			case 3: // User chooses to exit the program
			{
				cout << "Goodbye" << endl;
				running = false;
				break;
			}
			default:
				break;
			}
		}

		else
		{
			const int MENU_SIZE = 9; // Five options in this menu
			cout << endl;
			cout << "Press 1 to search for a word" << endl;
			cout << "Press 2 to find all words containing more than three 'z' characters" << endl;
			cout << "Press 3 to add a word to the Dictionary" << endl;
			cout << "Press 4 to find all palindromes" << endl;
			cout << "Press 5 to find rhyming words" << endl;
			cout << "Press 6 to play \"Guess The Fourth Word\"" << endl;
			cout << "Press 7 to cheat at Searchdle" << endl;
			cout << "Press 8 to load a different Dictionary file" << endl;
			cout << "Press 9 to exit" << endl;
			cout << endl;

			userInput = checkForValidIntInput(MENU_SIZE);

			switch (userInput)
			{
			case 1: // User is prompted to search for a word in the dictionary
			{
				string targetWord;
				cout << "Enter word:" << endl;
				cin >> targetWord;
				dictionary.getFullWordDetails(dictionary.searchWord(targetWord));
				break;
			}
			case 2: // Displays any/all words in the dictionary containing more than three 'z' characters
			{
				dictionary.findThreeZs();
				break;
			}
			case 3: // User is prompted to add a word to the dictionary
			{
				string wordToAdd;
				cout << "Enter word: " << endl;
				cin >> wordToAdd;
				if (dictionary.addWord(wordToAdd))
				{
					dictionary.saveToFile();
				}
				break;
			}
			case 4: // User chooses to list all palindromes in the dictionary
			{
				dictionary.displayPalindromes();
				break;
			}
			case 5: // User chooses to find all words rhyming with an input word
			{
				string wordToRhyme;
				cout << "Enter word to find all rhyming words:" << endl;
				cin >> wordToRhyme;
				dictionary.findRhymingWords(wordToRhyme);
				break;
			}
			case 6: // User chooses to play "Guess The Fourth Word"
			{
				dictionary.playGuessTheFourthWord();
				break;
			}
			case 7: // User chooses to cheat at Searchdle
			{
				dictionary.cheatAtSearchdle();
				break;
			}
			case 8: // User can return to the initial menu to load a different dictionary file
			{
				fileLoaded = false;
				break;
			}
			case 9: // User chooses to exit
			{
				running = false;
				break;
			}
			default:
				break;
			}
		}
	}
}

