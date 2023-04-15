//#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include "Word.h"
#include "Utilities.h"

class Dictionary
{
protected:
	std::vector<Word> wordList;

public:
	// Constructor
	Dictionary();

	// Methods
	void clear();
	bool loadFromFile(std::string);
	bool saveToFile();
	bool addWord(std::string);
	void addWordObject(Word);
	void deleteWord(std::string);
	int searchWord(std::string);
	void findThreeZs();

	// Setters and Getters
	void getWord(int);
	void getFullWordDetails(int);
	int getWordCount();
};
#endif