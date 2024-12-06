#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

#pragma once

class HangManGame
{
private:
    std::ofstream logFile;
    std::vector<std::string> words;
    std::string currentWord;
    int usedTries;

public:
    HangManGame();
    ~HangManGame();
    void AddLog(std::string &logText);
    bool StartRound();
};