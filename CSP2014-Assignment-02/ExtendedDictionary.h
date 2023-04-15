#pragma once
#include "Word.h"
#include "Dictionary.h"
class ExtendedDictionary :
    public Dictionary
{
private:

public:
    void displayPalindromes();
    void findRhymingWords(std::string);
    void playGuessTheFourthWord();
    void cheatAtSearchdle();
};

