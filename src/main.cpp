#include <SFML/Graphics.hpp>
#include <iostream>
#include "mario.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({512, 480}), "Mario Bros.");

    // making player
    Player mario;

    // clock to get delta time (interval between two frames)
    sf::Clock clock;

    // making ground sprites
    initGround();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
                window.close();
        }
        float dt = clock.restart().asSeconds();

        window.clear(); // clears the screen before rendering next frame

        // rendering ground and then player
        renderGround(window);
        mario.update(window,dt);
        // checkCollision
        mario.checkCollision(pipe_1, dt);
        mario.checkCollision(pipe_2, dt);
        mario.checkCollision(ground_1, dt);

        window.display(); // displaying things that we rendered above
    }

    return 0;
}