#include "paddle.h"

Paddle::Paddle(float x, float y) : speed(1000.f), velocity(0.f)
{
    shape.setSize({15.f, 100.f});
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
}

void Paddle::handle_input(sf::Keyboard::Key up, sf::Keyboard::Key down)
{
    velocity = 0.f;
    if (sf::Keyboard::isKeyPressed(up))
        velocity = -speed;
    if (sf::Keyboard::isKeyPressed(down))
        velocity = speed;
}

void Paddle::update(float dt)
{
    shape.move({0.f, velocity * dt});
}

void Paddle::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Paddle::north_bounce()
{
    velocity = -velocity;
}

//FIXME; setting up reset for after a score has been made
void Paddle::reset()
{
    shape.setPosition();
}

sf::FloatRect Paddle::get_bounds() const
{
    return shape.getGlobalBounds();
}