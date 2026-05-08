#pragma once 
#include <SFML/Graphics.hpp>

class Ball
{
    public:

        Ball(float x, float y, float r);
        void draw(sf::RenderWindow& window);
        void update(float dt);
        sf::FloatRect get_bounds() const;

    private:

        sf::CircleShape shape;
        float speed;
        float velocity;
}