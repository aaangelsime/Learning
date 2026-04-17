#include <SFML/Graphics.hpp>

/*

Steps for compiling new projects:
mkdir build
cd build
cmake ..
make 
./MyProject

Steps to compile:
make 
./MyProject

*/

int main() {
   
    sf::RenderWindow window(sf::VideoMode({500, 500}), "Pong");

    sf::RectangleShape player({50, 50});
    player.setFillColor(sf::Color::Green);
    player.setPosition({255, 255});

    sf::RectangleShape side_left({10, 100});
    side_left.setFillColor(sf::Color::White);
    side_left.setPosition({20, 250});

    sf::RectangleShape side_right({10, 100});
    side_right.setFillColor(sf::Color::White);
    side_right.setPosition({470, 250});

    sf::Clock clock;

    while(window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        while(const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            window.close();
        }

        float speed = 200.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            player.move({-speed * dt, 0});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            player.move({speed * dt, 0});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            player.move({0, -speed * dt});
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            player.move({0, speed * dt});

        window.clear(sf::Color::Black);
        window.draw(side_right);
        window.draw(side_left);
        window.draw(player);
        window.display();
        
    }

    return 0;
}

