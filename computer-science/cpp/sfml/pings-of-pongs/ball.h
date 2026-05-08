#pragma once 
#include <SFML/Graphics.hpp>

class Ball
{
    public:

        Ball(float x, float y, float r);
        void draw(sf::RenderWindow& window);
        void update(float dt);
        void bounce_y();
        void bounce_x();
        void reset();
        sf::FloatRect get_bounds() const;

    private:

        sf::CircleShape shape;
        sf::Vector2f velocity;
        float speed;

};