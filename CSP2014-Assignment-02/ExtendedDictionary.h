#pragma once
#include "Word.h"
#include "Dictionary.h"
#include "Utilities.h"

class ExtendedDictionary :
    public Dictionary
{
private:
    int guessTheFourthWordHighScore;
    std::string greyLetters;
    std::string yellowLetters;
    std::string greenLetters;
public:
    void displayPalindromes();
    void findRhymingWords(std::string);
    void playGuessTheFourthWord();
    void cheatAtSearchdle();

    int getGuessTheFourthWordHighScore();
    void setGuessTheFourthWordHighScore(int);
};

