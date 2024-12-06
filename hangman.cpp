#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include "./hangman.h"

#define WORDS_FILE "words.txt"
#define LOG_FILE "logs.txt"

HangManGame::HangManGame()
{
    logFile.open(LOG_FILE);

    std::ifstream wordFile;
    wordFile.open(WORDS_FILE);
    if (wordFile.is_open())
    {
        while (wordFile)
        {
            std::string line;
            std::getline(wordFile, line);
            words.push_back(line);
        }
        wordFile.close();
    }
}

HangManGame::~HangManGame()
{
    logFile.close();
}

void HangManGame::AddLog(std::string &logText)
{
    logFile << logText;
}