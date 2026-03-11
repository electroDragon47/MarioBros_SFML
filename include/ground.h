#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// ground
    extern sf::Texture t_ground; // the extern tells compiler This variable exists somewhere else,don’t create a new one here
    extern sf::RectangleShape ground;
    // pipe
    extern sf::Texture t_pipe_1;
    extern sf::RectangleShape pipe_1;
    extern sf::RectangleShape pipe_2;

    // single ground time
    extern sf::Texture t_ground_1;
    extern sf::RectangleShape ground_1;

    void initGround();
    void renderGround(sf::RenderWindow& window);