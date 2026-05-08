#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
    public:
        
        Paddle(float x, float y);
        void handle_input(sf::Keyboard::Key up, sf::Keyboard::Key down);
        void update(float dt);
        void draw(sf::RenderWindow& window);
        sf::FloatRect get_bounds() const;


    private:

        sf::RectangleShape shape;
        float speed;
        float velocity;
};