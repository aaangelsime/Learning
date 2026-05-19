/*
@ Author ; Angel Simental
@ Brief ; This is a Pong game using SFML
*/

/*
To compile and run g++ main.cpp game.cpp ball.cpp paddle.cpp -o pong -lsfml-graphics -lsfml-window -lsfml-system
*/
#include "game.h"

int main()
{
    Game game;
    game.run();
    return 0;
}
