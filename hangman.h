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
    void AddLog(std::string &logText);
    void PrintGuesses();

public:
    HangManGame();
    ~HangManGame();
    bool StartRound();
    void PlayRound();
    void ResetGame();
};