#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include "./hangman.h"

#define WORDS_FILE "words.txt"
#define LOG_FILE "logs.txt"
#define NUMBER_OF_TRIES 9;

HangManGame::HangManGame()
{
    logFile.open(LOG_FILE);

    std::ifstream wordFile;
    wordFile.open(WORDS_FILE);
    if (wordFile.is_open())
    {
        std::string line;
        while (std::getline(wordFile, line))
        {
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

bool HangManGame::StartRound()
{
    if (words.size() == 0)
    {
        printf("The game is over. No more words to play with.\n");
        return false;
    }
    else
    {
        usedTries = 0;
        currentWord = words[0];
        words.erase(words.begin());
        printf("New round has started.\n");
        return true;
    }
}
