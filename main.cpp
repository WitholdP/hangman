#include "./hangman.h"

int main()
{
	HangManGame game;

	while (true)
	{
		if (!game.StartRound())
		{
			break;
		}
	}

	return 0;
};
