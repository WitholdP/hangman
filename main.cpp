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
		game.PlayRound();
		game.ResetGame();
	}

	return 0;
};
