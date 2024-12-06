#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

#pragma once

class HangManGame
{
private:
    std::vector<std::string> words;
    std::ofstream logFile;

public:
    HangManGame();
    ~HangManGame();
    void AddLog(std::string &logText);
};