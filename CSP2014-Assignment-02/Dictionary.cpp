#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dictionary.h"
#include "Word.h"
#include "Utilities.h"

// Default Constructor
Dictionary::Dictionary() {}

// Method Implementation
/* James Boyd, Student ID: 10629572, 13/04/2023
* Clears the vector<Word> that holds all Word objects
*/
void Dictionary::clear()
{
	this->wordList.clear();
}


/* James Boyd, Student ID: 10629572, 13/04/2023
* Loads Word objects into the vector<Word> from a .txt file. File should be in format:
<word>
word name
word definition
word type
</word>
*/
bool Dictionary::loadFromFile(std::string filename)
{
	this->clear();
	std::fstream FileReader;
	FileReader.open(filename, std::ios::in);
	if (!FileReader) {
		std::cout << "File not found" << std::endl;
		return false;
	}
	else {
		std::cout << "Loading file \"" << filename << "\"..." << std::endl;
		while (!FileReader.eof())
		{
			std::string line;
			getline(FileReader, line);
			if (line == "<word>") // FileReader object reads line by line until reaching the open <word> tag
			{
				std::string name, type, definition = "";
				getline(FileReader, name);
				getline(FileReader, definition);
				getline(FileReader, type);
				Word newWord = Word(name, type, definition);
				//this->addWord(newWord);
				wordList.push_back(newWord);
			}
		}
		FileReader.close();
		return true;
	}
}


/* James Boyd, Student ID: 10629572, 13/04/2023
* Loops through vector<Word> and writes the name, type and definition of all Word objects to a
.txt file specified by the user
*/
bool Dictionary::saveToFile()
{
	std::string data;
	std::cout << "Enter a filename to save the dictionary file (.txt format)" << std::endl;
	std::cin >> data;
	std::string saveFileName = data + ".txt";

	std::fstream FileWriter;
	FileWriter.open(saveFileName, std::ios::out);
	if (!FileWriter) {
		return false;
	}
	else {
		FileWriter << "2023-S1 dictionary contains " << this->getWordCount() << " words" << std::endl;
		FileWriter << std::endl;

		for (Word word : wordList)
		{
			FileWriter << "<word>" << std::endl;
			FileWriter << word.getName() << std::endl;
			FileWriter << word.getDefinition() << std::endl;
			FileWriter << word.getType() << std::endl;
			FileWriter << "</word>" << std::endl;
		}

		FileWriter.close();
		std::cout << "File " << saveFileName << " saved" << std::endl;
		return true;
	}
}


/* James Boyd, Student ID: 10629572, 13/04/2023
* Adds a word to the dictionary. User is asked to type the word name, this string is searched
* to ensure the word doesn't already exist in the dictionary. If it does not exist, user is asked
* for type and definition and a Word object is instantiated and added to the vector<Word>
*/
bool Dictionary::addWord(std::string wordToAdd)
{
	if (this->searchWord(wordToAdd) < 0)
	{
		int wordTypeChoice;
		std::string name, type, definition = "";
		name = wordToAdd;

		const int MENU_SIZE = 8; // Eight options in this menu
		std::cout << "Choose a word type:" << std::endl;
		std::cout << "1: Noun  2: Verb  3: Adverb  4: Adjective  5: Preposition "  
			"6: Miscellaneous  7: Proper Noun  8: Noun and Verb" << std::endl;

		wordTypeChoice = checkForValidIntInput(MENU_SIZE);

		switch (wordTypeChoice)
		{
		case 1:
			type = "n";
			break;
		case 2:
			type = "v";
			break;
		case 3:
			type = "adv";
			break;
		case 4:
			type = "adj";
			break;
		case 5:
			type = "prep";
			break;
		case 6:
			type = "misc";
			break;
		case 7:
			type = "pn";
			break;
		case 8:
			type = "n_and_v";
			break;
		default:
			break;
		}

		std::string tempDefinition = "";
		std::cout << "Enter a definition:" << std::endl;
		getline(std::cin, tempDefinition); // dummy getline() call to consume the trailing newline from the word type code above
		getline(std::cin, tempDefinition);
		definition = tempDefinition;

		Word wordToAdd = Word(name, type, definition);

		wordList.push_back(wordToAdd);
		return true;
	}
	else
	{
		std::cout << "ERROR: Word exists, elevated privileges required to edit existing words" << std::endl;
		return false;
	}
}


/* James Boyd, Student ID: 10629572, 13/04/2023
* Searches for a word in the dictionary, implemented as a binary search algorithm. Returns -1 if the word 
* does not exist, returns the index of the word if it does
*/
int Dictionary::searchWord(std::string wordToSearch)
{
	for (int i = 0; i < wordToSearch.length(); i++)
	{
		wordToSearch[i] = tolower(wordToSearch[i]); // Converting search target to lower case for case-insensitivity
	}
	int lowerBound = 0;
	int upperBound = getWordCount();
	int mid = 0;
	bool found = false;

	while (lowerBound < upperBound)
	{
		mid = (upperBound + lowerBound) / 2;
		std::string midWord = wordList[mid].getName();
		if (!isalpha(midWord[0]))
		{
			midWord = midWord.substr(1, -1);
		}
		int comparison = (midWord.compare(wordToSearch));
		if (comparison == 0)
		{
			return mid;
		}
		else if (comparison < 0)
		{
			lowerBound = mid + 1;
		}
		else
		{
			upperBound = mid;
		}
	}
	if (!found)
	{
		return -1;
	}
}


/* James Boyd, Student ID: 10629572, 13/04/2023
* Searches the vector<Word> for any words that contain more than three 'z' characters. Prints the full
* word details of all matching words, or an error message if none is found
*/
void Dictionary::findThreeZs()
{
	std::cout << "Displaying all words containing more than three 'z' characters: " << std::endl;
	int zCounter = 0;
	for (Word word : wordList)
	{
		for (char y : word.getName())
		{
			if (y == 'z')
			{
				zCounter++;
			}
		}
		if (zCounter > 2)
		{
			word.printDefinition();
		}
	}
	if (zCounter == 0)
	{
		std::cout << "ERROR: No matching words found" << std::endl;
	}
}


// SETTERS & GETTERS
void Dictionary::getWord(int index)
{
	if (index >= 0)
	{
		this->wordList[index].printWordNameOnly();
	}
	else
	{
		std::cout << "ERROR: Word not found" << std::endl;
	}
}

void Dictionary::getFullWordDetails(int index)
{
	if (index >= 0)
	{
		this->wordList[index].printDefinition();
	}
	else
	{
		std::cout << "ERROR: Word not found" << std::endl;
	}
}

int Dictionary::getWordCount()
{
	return this->wordList.size();
}