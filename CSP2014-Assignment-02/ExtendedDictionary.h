#pragma once
#include "Word.h"
#include "Dictionary.h"
#include "Utilities.h"

class ExtendedDictionary :
    public Dictionary
{
private:
    int guessTheFourthWordHighScore;
public:
    void displayPalindromes();
    void findRhymingWords(std::string);
    void playGuessTheFourthWord();
    void cheatAtSearchdle();

    int getGuessTheFourthWordHighScore();
    void setGuessTheFourthWordHighScore(int);
};

