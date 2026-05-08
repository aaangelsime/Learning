#pragma once
#include "paddle.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

enum class Game_State {Menu, Playing, Paused};

class Game
{
    public:

        Game();
        void run();

    private:

        void handle_events();
        void update(float dt);
        void render();
        void check_collision();

        sf::RenderWindow window;
        sf::Clock clock;
        Game_State state;

        Paddle player_one;
        Paddle player_two;
        Ball ball;

        int score_one;
        int score_two;
};