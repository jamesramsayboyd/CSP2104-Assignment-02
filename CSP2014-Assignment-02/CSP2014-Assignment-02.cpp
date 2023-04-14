#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "Word.h"
#include "Dictionary.h"
//#include "Utilities.h"

using namespace std;

#pragma region FUNCTIONS

/* James Boyd, Student ID: 10629572, 11/04/2023
A function that prints the details of a word (name, type, definition) to the console formatted
in the manner specified in Task 2, Table 1 of the assignment document. Used repeatedly throughout
the program. Requires a vector<Word> and an index value to print a word's details. */
//void PrintWordDetails(vector<Word>* Dictionary, int index)
//{
//	if (index < 0)
//	{
//		cout << "Word not found" << endl;
//	}
//	else
//	{
//		Word word = (*Dictionary)[index];
//		cout << "Word: " << word.getName() << endl;
//		cout << "Type: ";
//		if (word.getType() == "n")
//		{
//			cout << "[noun]" << endl;
//		}
//		else if (word.getType() == "v")
//		{
//			cout << "[verb]" << endl;
//		}
//		else if (word.getType() == "adv")
//		{
//			cout << "[adverb]" << endl;
//		}
//		else if (word.getType() == "adj")
//		{
//			cout << "[adjective]" << endl;
//		}
//		else if (word.getType() == "prep")
//		{
//			cout << "[preposition]" << endl;
//		}
//		else if (word.getType() == "misc")
//		{
//			cout << "[miscellaneous]" << endl;
//		}
//		else if (word.getType() == "pn")
//		{
//			cout << "[proper noun]" << endl;
//		}
//		else if (word.getType() == "n_and_v")
//		{
//			cout << "[noun and verb]" << endl;
//		}
//		else
//		{
//			cout << "[unknown]" << endl;
//		}
//		cout << "Definition: " << word.getDefinition() << endl;
//	}
//}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function to load the contents of a .txt file into the vector as objects of type Word
.txt file should be in format:
<word>
word name
word type
word definition
</word>
etc, as specified in Task 1 of the assignment document. */
//bool LoadDictionary(vector<Word>* Dictionary, string filename)
//{
//	Dictionary->clear();
//	fstream FileReader;
//	FileReader.open(filename, ios::in);
//	if (!FileReader) {
//		cout << "File not found" << endl;
//		return false;
//	}
//	else {
//		cout << "Loading file \"" << filename << "\"..." << endl;
//		while (!FileReader.eof())
//		{
//			string line;
//			getline(FileReader, line);
//			if (line == "<word>") // FileReader object reads line by line until reaching the open <word> tag
//			{
//				string name, type, definition = "";
//				getline(FileReader, name);
//				getline(FileReader, definition);
//				getline(FileReader, type);
//				Word newWord = Word(name, type, definition);
//				Dictionary->push_back(newWord);
//			}
//		}
//		FileReader.close();
//		return true;
//	}
//}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function that saves all Word objects in the provided vector<Word> to a .txt file. The user is prompted
to enter an appropriate filename, as specified in Task 4 of the assignment document. */
//bool SaveDictionaryToFile(vector<Word>* Dictionary)
//{
//	string data;
//	cout << "Enter a filename to save the dictionary file (.txt format)" << endl;
//	cin >> data;
//	string saveFileName = data + ".txt";
//
//	fstream FileWriter;
//	FileWriter.open(saveFileName, ios::out);
//	if (!FileWriter) {
//		return false;
//	}
//	else {
//		FileWriter << "2023-S1 dictionary contains " << Dictionary->size() << " words" << endl;
//		FileWriter << endl;
//
//		for (int i = 0; i < Dictionary->size(); i++)
//		{
//			FileWriter << "<word>" << endl;
//			FileWriter << (*Dictionary)[i].getName() << endl;
//			FileWriter << (*Dictionary)[i].getType() << endl;
//			FileWriter << (*Dictionary)[i].getDefinition() << endl;
//			FileWriter << "</word>" << endl;
//		}
//		FileWriter.close();
//		cout << "File " << saveFileName << " saved" << endl;
//		return true;
//	}
//}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function to search for a user-entered word in the dictionary vector. The function then
uses a binary search algorithm to search for the word in the dictionary. If a match
is found, the word's information is printed to the console. The function returns the integer
index of the word if found, or -1 if not found. */
//int SearchForWord(vector<Word>* Dictionary, string targetWord)
//{
//	//for (int i = 0; i < targetWord.length(); i++)
//	//{
//	//	targetWord[i] = tolower(targetWord[i]); // Converting search target to all lower case for case-insensitive searches
//	//}
//	//int lowerBound = 0;
//	//int upperBound = Dictionary->size();
//	//int mid = 0;
//	//bool found = false;
//
//	//while (lowerBound < upperBound)
//	//{
//	//	mid = (upperBound + lowerBound) / 2;
//	//	string midWord = (*Dictionary)[mid].getName();
//	//	if (!isalpha(midWord[0])) // Extra check needed because some words in the provided dictionary file start with a "-" character
//	//	{
//	//		midWord = midWord.substr(1, -1);
//	//	}
//	//	int comparison = (midWord.compare(targetWord));
//	//	if (comparison == 0)
//	//	{
//	//		return mid;
//	//	}
//	//	else if (comparison < 0)
//	//	{
//	//		lowerBound = mid + 1;
//	//	}
//	//	else
//	//	{
//	//		upperBound = mid;
//	//	}
//	//}
//
//	//if (!found)
//	//{
//	//	return -1;
//	//}
//	return 0;
//}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function that uses nested for loops to iterate through each character of each word
When a 'z' character is found, the integer 'zCounter' is increased by 1. If zCounter
reaches 3 or greater, the word details are displayed, as specified in Task 3 of the assignment document. */
//void FindThreeZs(vector<Word>* Dictionary)
//{
//	for (int i = 0; i < Dictionary->size(); i++)
//	{
//		int zCounter = 0;
//		for (int j = 0; j < (*Dictionary)[i].getName().size(); j++)
//		{
//			if ((*Dictionary)[i].getName()[j] == 'z')
//			{
//				zCounter++;
//			}
//		}
//		if (zCounter > 2)
//		{
//			PrintWordDetails(Dictionary, i);
//		}
//	}
//}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function that allows the user to add a word to the dictionary. The user is prompted
to enter a word name, a word type (chosen from a pre-defined list) and a definition. If valid,
the word is added to the dictionary, as specified in Task 4 of the assignment document. Error
message is word already exists in dictionary. */
//bool AddWordToDictionary(vector<Word>* Dictionary, string addWord)
//{
//	if (SearchForWord(Dictionary, addWord) < 0)
//	{
//		int wordTypeChoice;
//		string name, type, definition = "";
//		name = addWord;
//
//		const int MENU_SIZE = 8; // Eight options in this menu
//		cout << "Choose a word type:" << endl;
//		cout << "1: Noun  2: Verb  3: Adverb  4: Adjective  5: Preposition  6: Miscellaneous  7: Proper Noun  8: Noun and Verb" << endl;
//
//		wordTypeChoice = CheckForValidIntInput(MENU_SIZE);
//
//		switch (wordTypeChoice)
//		{
//		case 1:
//			type = "n";
//			break;
//		case 2:
//			type = "v";
//			break;
//		case 3:
//			type = "adv";
//			break;
//		case 4:
//			type = "adj";
//			break;
//		case 5:
//			type = "prep";
//			break;
//		case 6:
//			type = "misc";
//			break;
//		case 7:
//			type = "pn";
//			break;
//		case 8:
//			type = "n_and_v";
//			break;
//		default:
//			break;
//		}
//
//		string tempDefinition = "";
//		cout << "Enter a definition:" << endl;
//		getline(cin, tempDefinition); // dummy getline() call to consume the trailing newline from the word type code above
//		getline(cin, tempDefinition);
//		definition = tempDefinition;
//
//		Word wordToAdd = Word(name, type, definition);
//
//		Dictionary->push_back(wordToAdd);
//		return true;
//	}
//	else
//	{
//		cout << "ERROR: Word exists, elevated privileges required to edit existing words" << endl;
//		return false;
//	}
//}

#pragma endregion FUNCTIONS

int main()
{
	Dictionary dictionary = Dictionary();
	bool running = true; // A boolean tracking whether the program is running, updated to false when the user chooses to exit
	bool fileLoaded = false; // A boolean tracking whether a .txt file has been loaded
	int userInput = 0;
	//const string DEFAULT_DICTIONARY_NAME = "dictionary_2023S1.txt"; // The .txt file provided for the assignment
	const string DEFAULT_DICTIONARY_NAME = "dictionary_test.txt"; // The .txt file provided for the assignment

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

			userInput = CheckForValidIntInput(MENU_SIZE);

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
			const int MENU_SIZE = 5; // Five options in this menu
			cout << endl;
			cout << "Press 1 to search for a word" << endl;
			cout << "Press 2 to find all words containing more than three 'z' characters" << endl;
			cout << "Press 3 to add a word to the Dictionary" << endl;
			cout << "Press 4 to load a different Dictionary file" << endl;
			cout << "Press 5 to exit" << endl;
			cout << endl;

			userInput = CheckForValidIntInput(MENU_SIZE);

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
				cout << "Displaying all words containing more than three 'z' characters: " << endl;
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
			case 4: // User can return to the initial menu to load a different dictionary file
			{
				fileLoaded = false;
				break;
			}
			case 5: // User chooses to exit the program
			{
				cout << "Goodbye" << endl;
				running = false;
				break;
			}
			default:
				break;
			}
		}
	}
}

