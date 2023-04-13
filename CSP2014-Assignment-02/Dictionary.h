#pragma once

#include <vector>
#include <string>
#include "Word.h"

class Dictionary
{
private:
	//static std::vector<Word> wordList;

public:
	static std::vector<Word> wordList;

	// Constructor
	Dictionary();

	// Methods
	void clear();
	void loadFromFile(std::string);
	void saveToFile();
	void addWord(Word);
	void deleteWord(Word);
	Word searchWord(std::string);
	Word findThreeZs();

	// Setters and Getters
	int getWordCount();
};