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
void Dictionary::clear()
{
	this->wordList.clear();
}

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

		wordTypeChoice = CheckForValidIntInput(MENU_SIZE);

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


void Dictionary::deleteWord(std::string wordToDelete)
{
	int deleteIndex = searchWord(wordToDelete);
	if (deleteIndex >= 0)
	{
		wordList.erase(wordList.begin() + deleteIndex); // TODO: Consider changing searchWord to return vector iterator
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

int Dictionary::searchWord(std::string wordToSearch)
{
	for (int i = 0; i < getWordCount(); i++)
	{
		if (wordList[i].getName() == wordToSearch)
		{
			return i;
		}
	}
	return -1;
}

void Dictionary::findThreeZs()
{
	for (Word word : wordList)
	{
		int zCounter = 0;
		for (char y : word.getName())
		{
			if (y == 'z')
			{
				zCounter++;
			}
		}
		if (zCounter > 2)
		{
			//break; // TODO: Think about this break
			word.printDefinition();
		}
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