#pragma once
#include "Word.h"
#include "Dictionary.h"
#include "Utilities.h"

class ExtendedDictionary :
    public Dictionary
{
private:
    int guessTheFourthWordHighScore = 0;
    std::string greyLetters;
    std::string yellowLetters;
    std::string greenLetters;
    std::vector<Word> potentialSearchdleAnswers;
public:
    void displayPalindromes();
    void findRhymingWords(std::string);
    void playGuessTheFourthWord();
    void cheatAtSearchdle();
    void trimSearchdleAnswerSize(int wordLength);
    void inputSearchdleGuess(int);
    void printSearchdleAnswer();

    int getGuessTheFourthWordHighScore();
    void setGuessTheFourthWordHighScore(int);
};

