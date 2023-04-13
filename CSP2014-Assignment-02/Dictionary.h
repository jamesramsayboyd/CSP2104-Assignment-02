#pragma once

#include <vector>
#include <string>
#include "Word.h"

class Dictionary
{
private:
	std::vector<Word> wordList;

public:
	// Constructor
	Dictionary();

	// Methods
	void clear();
	void loadFromFile(std::string);
	void saveToFile();
	void addWord(Word);
	void deleteWord(std::string);
	int searchWord(std::string);
	void findThreeZs();

	// Setters and Getters
	int getWordCount();
};