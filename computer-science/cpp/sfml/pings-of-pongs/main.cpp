#include <SFML/Graphics.hpp>


int main()
{
    // recall sf = namespace; RenderWindow = class; window = object name; (....) = constructor arguments

    sf::RenderWindow window(sf::VideoMode({1000,1000}), "Here we go");

    // starting text
    // sf::Font font("Ubuntu-B.ttf");

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
    text_one.setPosition(370.f, 180.f);

    sf::Text text_two;
    text_two.setFont(font);
    text_two.setString("to begin, press the space bar");
    text_two.setCharacterSize(24);
    text_two.setFillColor(sf::Color::White);
    text_two.setPosition(350.f, 250.f);


    // pong chars
    sf::CircleShape pong(20.f);
    pong.setFillColor(sf::Color::White);
    pong.setPosition(500.f, 500.f);

    // left paddle
    sf::RectangleShape paddle_one(sf::Vector2f(15.f, 100.f));
    paddle_one.setFillColor(sf::Color::White);
    paddle_one.setPosition(100.f, 500.f);

    // right paddle
    sf::RectangleShape paddle_two(sf::Vector2f(15.f, 100.f));
    paddle_two.setFillColor(sf::Color::White);
    paddle_two.setPosition(900.f, 500.f);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            window.close();
        }

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