#include <ball.h>

Ball::Ball(float x, float y, float r)
{
    shape.setSize(r);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
}

void Ball::update(float dt)
{
    
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::FloatRect Ball::get_bounds() const
{
    return shape.getGlobalBounds();
}