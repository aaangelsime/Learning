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

        sf::Font font;
        sf::Text main_intro;
        sf::Text main_space;
        sf::Text player_one_score;
        sf::Text player_two_score;

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