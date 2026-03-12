#include <SFML/Graphics.hpp>
#include <iostream>
#include "mario.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({512, 480}), "Mario Bros.");
    return game(window);
}

int game(sf::RenderWindow &window)
{
    Player mario;
    Enemy turtle;
    sf::Clock clock;

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::K))
            game(window);

        window.clear(); // clears the screen before rendering next frame

        // rendering ground and player and enemy
        renderGround(window);
        mario.update(window,dt);
        turtle.update(window,dt);
        // checkCollision
        mario.checkCollision(pipe_1, dt);
        mario.checkCollision(pipe_2, dt);
        mario.checkCollision(bigpipe_l,dt);
        mario.checkCollision(bigpipe_2,dt);
        mario.checkCollision(platform_1,dt);
        mario.checkCollision(platform_2,dt);
        mario.checkCollision(platform_3,dt);
        mario.checkCollision(platform_4,dt);
        mario.checkCollision(platform_5,dt);
        mario.checkCollision(platform_6,dt);
        mario.checkCollision(platform_7,dt);

        window.display(); // displaying things that we rendered above
    }

    return 0;
}