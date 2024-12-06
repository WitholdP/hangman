#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include "./hangman.h"

#define WORDS_FILE "words.txt"
#define LOG_FILE "high_scores.txt"
#define NUMBER_OF_TRIES 9;

HangManGame::HangManGame()
{
    triesLeft = NUMBER_OF_TRIES;
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
        currentWord = words[0];
        words.erase(words.begin());
        printf("New round has started.\n");
        return true;
    }
}

void HangManGame::PrintGuesses()
{
    for (auto const letter : madeGuessed)
    {
        printf(" %c,", letter);
    }
}

void HangManGame::PlayRound()
{
    while (true)
    {
        printf("The guesses you have made are: ");
        PrintGuesses();
        std::cout << std::endl;

        std::vector<bool> notGuessed;
        for (const char letter : currentWord)
        {
            if (guessedLetters.find(letter) != guessedLetters.end())
            {
                printf("%c ", letter);
            }
            else
            {
                notGuessed.push_back(true);
                printf("_ ");
            }
        }
        std::cout << std::endl;

        if (notGuessed.empty())
        {
            printf("You have guessed all the letters.\n");
            printf("You get %i points.\n", triesLeft);
            break;
        }

        if (triesLeft == 0)
        {
            printf("You don't have any tries left.\n");
            break;
        }

        std::cout << std::endl;
        printf("You have %i tries left.\n", triesLeft);
        printf("What is your guess?\n");
        char playerInput;
        std::cin >> playerInput;

        char upperInput = std::toupper(playerInput);

        if (currentWord.find(upperInput) != std::string::npos)
        {
            printf("You have guessed letter: %c\n", upperInput);
            guessedLetters.insert(upperInput);
        }
        else
        {
            triesLeft--;
            printf("The letter: %c is not in the word.\n", upperInput);
        }
        madeGuessed.insert(upperInput);
        std::cout << std::endl;
    }
}

void HangManGame::ResetGame()
{
    triesLeft = NUMBER_OF_TRIES;
    guessedLetters.clear();
}