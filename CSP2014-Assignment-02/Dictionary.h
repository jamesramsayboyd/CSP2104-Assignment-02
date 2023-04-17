#pragma once

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
	int searchWord(std::string);
	void findThreeZs();

	// Setters and Getters
	void getWord(int);
	void getFullWordDetails(int);
	int getWordCount();
};