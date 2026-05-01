/*
@ Author ; Angel Simental
@ Brief ; This is a Pong game using SFML
*/
#include <SFML/Graphics.hpp>

int main()
{
    // delta time
    sf::Clock clock;
    
    // recall sf = namespace; RenderWindow = class; window = object name; (....) = constructor arguments
    sf::RenderWindow window(sf::VideoMode({1000,1000}), "Here we go");

    // font for text
    sf::Font font;
    if (!font.loadFromFile("ubuntu/Ubuntu-B.ttf"))
    {
        return -1;
    }

    // heading one
    sf::Text text_one;
    text_one.setFont(font);
    text_one.setString("Welcome To Pong");
    text_one.setCharacterSize(34);
    text_one.setFillColor(sf::Color::White);
    text_one.setPosition(370.f, 60.f);

    // heading two
    sf::Text text_two;
    text_two.setFont(font);
    text_two.setString("to begin, press the space bar");
    text_two.setCharacterSize(24);
    text_two.setFillColor(sf::Color::White);
    text_two.setPosition(350.f, 110.f);

    // pong chars
    sf::CircleShape pong(20.f);
    pong.setFillColor(sf::Color::White);
    pong.setPosition(490.f, 500.f);

    // left paddle
    sf::RectangleShape paddle_one(sf::Vector2f(15.f, 100.f));
    paddle_one.setFillColor(sf::Color::White);
    paddle_one.setPosition(100.f, 500.f);

    // right paddle
    sf::RectangleShape paddle_two(sf::Vector2f(15.f, 100.f));
    paddle_two.setFillColor(sf::Color::White);
    paddle_two.setPosition(900.f, 500.f);

    // variables for w & s tracking
    bool w_pressed = false;
    bool s_pressed = false;

    while(window.isOpen())
    {
        // seconds since last frame
        float dt = clock.restart().asSeconds();
        int paddle_speed = 1000;
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            window.close();

            // tracks w & s key state for left paddle movement
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                w_pressed = true;
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
                w_pressed = false;
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                s_pressed = true;
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
                s_pressed = false;
        }

        // w & s controls / movements
        if(w_pressed)
            paddle_one.move({0.f, -paddle_speed * dt});
        if(s_pressed)
            paddle_one.move({0.f, paddle_speed * dt});

        window.clear();
        window.draw(text_one);
        window.draw(text_two);
        window.draw(pong);
        window.draw(paddle_one);
        window.draw(paddle_two);
        window.display();

    }

    return 0;
}