#pragma once
#include "Word.h"
#include "Dictionary.h"
#include "Utilities.h"

class ExtendedDictionary :
    public Dictionary
{
private:
    int guessTheFourthWordHighScore = 0;
    bool searchdleRunning = false;
    bool answerFound = false;
    std::string greyLetters;
    std::string yellowLetters;
    std::string greenLetters;
    std::vector<Word> potentialSearchdleAnswers;
public:
    void displayPalindromes();
    void findRhymingWords(std::string);
    void playGuessTheFourthWord();
    void cheatAtSearchdle();
    void trimSearchdleAnswerPool(int wordLength);
    void inputSearchdleGuess(int);
    void checkSearchdleAnswer();

    int getGuessTheFourthWordHighScore();
    void setGuessTheFourthWordHighScore(int);
    bool getSearchdleRunning();
    void setSearchdleRunning(bool);
    bool getAnswerFound();
    void setAnswerFound(bool);
};

