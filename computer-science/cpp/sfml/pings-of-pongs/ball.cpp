#include "ball.h"

Ball::Ball(float x, float y, float r) : speed(400.f)
{
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
    velocity = {speed, speed};
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Ball::update(float dt)
{
    shape.move(velocity * dt);
}

void Ball::bounce_x()
{
    velocity.x = -velocity.x;
}

void Ball::bounce_y()
{
    velocity.y = -velocity.y;
}

void Ball::reset()
{
    shape.setPosition(490.f, 500.f);
    velocity = {speed, speed};
}


sf::FloatRect Ball::get_bounds() const
{
    return shape.getGlobalBounds();
}