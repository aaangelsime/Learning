#include "game.h"

Game::Game()    
    : window(sf::VideoMode({1000, 1000}), "Pong"),
      state(Game_State::Menu),
      player_one(100.f, 500.f),
      player_two(900.f, 500.f),
      ball(490.f, 500.f, 20.f),
      score_one(0), score_two(0)
    {
        font.loadFromFile("Ubuntu-B.ttf");

        main_intro.setString("Welcome to Pong");
        main_intro.setFont(font);
        main_intro.setCharacterSize(50);
        main_intro.setFillColor(sf::Color::White);
        sf::FloatRect b1 = main_intro.getLocalBounds();
        main_intro.setOrigin(b1.width / 2.f, b1.height / 2.f); 
        main_intro.setPosition(500.f, 200.f);                    

        main_space.setString("To start press SPACE");
        main_space.setFont(font);
        main_space.setCharacterSize(30);
        main_space.setFillColor(sf::Color::White);
        sf::FloatRect b2 = main_space.getLocalBounds();
        main_space.setOrigin(b2.width / 2.f, b2.height / 2.f);
        main_space.setPosition(500.f, 320.f);

        //FIXME; add score_one into the text 
        player_one_score.setString("Player 1:");
        player_one_score.setFont(font);
        player_one_score.setCharacterSize(30);
        player_one_score.setFillColor(sf::Color::White);
        player_one_score.setPosition(100.f, 75.f);

        //FIXME; add score_two into the text
        player_two_score.setString("Player 2:");
        player_two_score.setFont(font);
        player_two_score.setCharacterSize(30);
        player_two_score.setFillColor(sf::Color::White);
        player_two_score.setPosition(800.f, 75.f);
    }

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
    auto ball_pos = ball.get_bounds();
    sf::FloatRect one_pos = player_one.get_bounds();
    sf::FloatRect two_pos = player_two.get_bounds();
    // ball collision

    /*
    "object".top is the y cord of the objects top edge. 
    */
    if (ball_pos.top <= 0 || ball_pos.top + ball_pos.height >= 1000.f)
    {
        ball.bounce_y();
    }

    // paddle collision with the ball
    if (ball.get_bounds().intersects(player_one.get_bounds()) ||
        ball.get_bounds().intersects(player_two.get_bounds()))
    {
        ball.bounce_x();
    }

    // paddle 1 collision with the bounds
    if (one_pos.top <= 0)
    {
        // (initial x position, y top bound + 75)
        player_one.reset(100.f, 75.f);
    }
    if (one_pos.top >= 1000)
    {
        player_one.reset(100.f, 900.f);
    }

    // paddle 2 collision with the bounds
    if (two_pos.top <= 0)
    {
        player_two.reset(900.f, 75.f);
    }
    if (two_pos.top >= 1000)
    {
        player_two.reset(900.f, 900.f);
    }

    // score
    if (ball_pos.left <= 0)
    {
        score_two++; 
        ball.reset();
        player_one.reset(100.f, 500.f);
        player_two.reset(900.f, 500.f);
    }

    if (ball_pos.left + ball_pos.width >= 1000.f)
    {
        score_one++;
        ball.reset();
        player_one.reset(100.f, 500.f);
        player_two.reset(900.f, 500.f);
    }
}

void Game::render()
{
    window.clear();

    if (state == Game_State::Menu)
    {
        window.draw(main_intro);
        window.draw(main_space);
        

    }
    else
    {
    player_one.draw(window);
    player_two.draw(window);
    window.draw(player_one_score);
    window.draw(player_two_score);
    ball.draw(window);
    }

    window.display();
}

