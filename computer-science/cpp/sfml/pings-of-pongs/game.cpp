#include "game.h"

Game::Game()    
    : window(sf::VideoMode({1000, 1000}), "Pong"),
      state(Game_State::Menu),
      player_one(100.f, 500.f),
      player_two(900.f, 500.f),
      ball(490.f, 500.f, 20.f),
      score_one(0), score_two(0)
    {}

void Game::run()
{
    while(window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        handle_events();
        if (state == Game_State::Playing)
        {
            update(dt);
        }
        render();
    }
}

void Game::handle_events()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Space) 
            state = Game_State::Playing;
    }
}

void Game::update(float dt)
{
    player_one.handle_input(sf::Keyboard::W, sf::Keyboard::S);
    player_two.handle_input(sf::Keyboard::Up, sf::Keyboard::Down);
    player_one.update(dt);
    player_two.update(dt);
    ball.update(dt);
    check_collision();
}

void Game::check_collision()
{
    auto pos = ball.get_bounds();
    
    // ball collision
    if (pos.top <= 0 || pos.top + pos.height >= 1000.f)
    {
        ball.bounce_y();
    }

    // paddle collision
    if (ball.get_bounds().intersects(player_one.get_bounds()) ||
        ball.get_bounds().intersects(player_two.get_bounds()))
    {
        ball.bounce_x();
    }

    // score
    if (pos.left <= 0)
    {
        score_two++; 
        ball.reset();
    }

    if (pos.left + pos.width >= 1000.f)
    {
        score_one++;
        ball.reset();
    }

}

void Game::render()
{
    window.clear();
    player_one.draw(window);
    player_two.draw(window);
    ball.draw(window);
    window.display();
}

