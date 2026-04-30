#include <SFML/Graphics.hpp>

/*

Steps for compiling new projects:
mkdir build
cd build
cmake ..
make 
./MyProject

Steps to compile:
cd build
make 
./MyProject

*/

// left & right padle
class Paddle
{
    private:
        sf::RectangleShape shape;
        float speed;

    public:

        // paddle details
        Paddle(sf::Vector2f position, float speed)
        {
            shape = sf::RectangleShape({15,80});
            shape.setFillColor(sf::Color::White);
            shape.setPosition(position);
            this->speed = speed;
        }

        // paddle motion
        void handle_input(float dt)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                shape.move({0, -speed * dt});
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                shape.move({0, speed * dt});
        }

        void clamp()
        {
            sf::Vector2f pos = shape.getPosition();
            if (pos.y < 0)
                shape.setPosition({pos.x, 0});
            if (pos.y + 80 > 500)
                shape.setPosition({pos.x, 420});
        }

        sf::FloatRect get_bounds()
        {
            return shape.getGlobalBounds();
        }

        void draw(sf::RenderWindow& window)
        {
            window.draw(shape);
        }

};


class Circle
{
    private:

    public:

};

int main()
{
    sf::RenderWindow window(sf::VideoMode({500, 500}), "Pong");

    Paddle left_paddle({20, 210}, 300.f);
    Paddle right_paddle({465, 210}, 300.f);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        left_paddle.handle_input(dt);
        left_paddle.clamp();

        window.clear(sf::Color::Black);
        left_paddle.draw(window);
        right_paddle.draw(window);
        window.display();
    }

    return 0;
}

