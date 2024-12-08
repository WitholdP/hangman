#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <set>

#pragma once

class HangManGame
{
private:
    std::ofstream logFile;
    std::vector<std::string> words;
    std::string currentWord;
    std::set<char> guessedLetters;
    std::set<char> madeGuessed;
    int triesLeft;
    void PrintGuesses();
    void AddLog(std::string &logText);

public:
    HangManGame();
    ~HangManGame();
    bool StartRound();
    void PlayRound();
    void ResetGame();
    void PrintScores();
};