#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dictionary.h"
#include "Word.h"

// Default Constructor
Dictionary::Dictionary() {}

// Method Implementation
void Dictionary::clear()
{
	this->wordList.clear();
}

void Dictionary::loadFromFile(std::string filename)
{
	this->clear();
	std::fstream FileReader;
	FileReader.open(filename, std::ios::in);
	if (!FileReader) {
		std::cout << "File not found" << std::endl;
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
				this->addWord(newWord);
			}
		}
		FileReader.close();
	}
}


void Dictionary::saveToFile()
{
	std::string data;
	std::cout << "Enter a filename to save the dictionary file (.txt format)" << std::endl;
	std::cin >> data;
	std::string saveFileName = data + ".txt";

	std::fstream FileWriter;
	FileWriter.open(saveFileName, std::ios::out);
	if (!FileWriter) {
		//return false;
	}
	else {
		FileWriter << "2023-S1 dictionary contains " << this->getWordCount() << " words" << std::endl;
		FileWriter << std::endl;

		for (Word x : wordList)
		{
			FileWriter << "<word>" << std::endl;
			FileWriter << x.getName() << std::endl;
			FileWriter << x.getType() << std::endl;
			FileWriter << x.getDefinition() << std::endl;
			FileWriter << "</word>" << std::endl;
		}

		FileWriter.close();
		std::cout << "File " << saveFileName << " saved" << std::endl;
		//return true;
	}
}


void Dictionary::addWord(Word wordToAdd)
{
	//if (SearchForWord(Dictionary, addWord) < 0)
	//{
	//	int wordTypeChoice;
	//	string name, type, definition = "";
	//	name = addWord;

	//	const int MENU_SIZE = 8; // Eight options in this menu
	//	cout << "Choose a word type:" << endl;
	//	cout << "1: Noun  2: Verb  3: Adverb  4: Adjective  5: Preposition  6: Miscellaneous  7: Proper Noun  8: Noun and Verb" << endl;

	//	wordTypeChoice = CheckForValidIntInput(MENU_SIZE);

	//	switch (wordTypeChoice)
	//	{
	//	case 1:
	//		type = "n";
	//		break;
	//	case 2:
	//		type = "v";
	//		break;
	//	case 3:
	//		type = "adv";
	//		break;
	//	case 4:
	//		type = "adj";
	//		break;
	//	case 5:
	//		type = "prep";
	//		break;
	//	case 6:
	//		type = "misc";
	//		break;
	//	case 7:
	//		type = "pn";
	//		break;
	//	case 8:
	//		type = "n_and_v";
	//		break;
	//	default:
	//		break;
	//	}

	//	string tempDefinition = "";
	//	cout << "Enter a definition:" << endl;
	//	getline(cin, tempDefinition); // dummy getline() call to consume the trailing newline from the word type code above
	//	getline(cin, tempDefinition);
	//	definition = tempDefinition;

	//	Word wordToAdd = Word(name, type, definition);

	//	Dictionary->push_back(wordToAdd);
	//	return true;
	//}
	//else
	//{
	//	cout << "ERROR: Word exists, elevated privileges required to edit existing words" << endl;
	//	return false;
	//}
	wordList.push_back(wordToAdd);
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
	for (Word x : wordList)
	{
		int zCounter = 0;
		for (char y : x.getName())
		{
			if (y == 'z')
			{
				zCounter++;
			}
		}
		if (zCounter > 2)
		{
			break; // TODO: Think about this break
			x.printDefinition();
		}
	}
}

int Dictionary::getWordCount()
{
	return this->wordList.size();
}