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
	wordList.clear();
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
	wordList.push_back(wordToAdd);
	//wordList.sort();
}


void Dictionary::deleteWord(Word wordToDelete)
{
	//wordList.erase(wordToDelete); TODO: 
}

Word Dictionary::searchWord(std::string)
{
	return Word("test", "test", "test");
}

Word Dictionary::findThreeZs()
{
	/*for (int i = 0; i < Dictionary->size(); i++)
	{
		int zCounter = 0;
		for (int j = 0; j < (*Dictionary)[i].getName().size(); j++)
		{
			if ((*Dictionary)[i].getName()[j] == 'z')
			{
				zCounter++;
			}
		}
		if (zCounter > 2)
		{
			PrintWordDetails(Dictionary, i);
		}
	}*/
	return Word("a", "b", "c");
}

int Dictionary::getWordCount()
{
	return wordList.size();
}