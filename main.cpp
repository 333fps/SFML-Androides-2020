/*

*************************************************************************
*          GameCodeur - Game Jam #24 - Androides 2020 / 333fps          *
*                                v1.5                                   *
*************************************************************************

*/

#include "GameEngine.h"
#include "DEFINITIONS.h"

int main()
{
	GameEngine gameEngine(SCREEN_WIDTH, SCREEN_HEIGHT, "Androides 2020");

	gameEngine.Run();

	return 0;
}
