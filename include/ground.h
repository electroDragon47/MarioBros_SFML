#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// ground
    extern sf::Texture t_ground; // the extern tells compiler This variable exists somewhere else,don’t create a new one here
    extern sf::RectangleShape ground;
    // pipe
    extern sf::Texture smallPipe;
    extern sf::Texture bigPipe;
    extern sf::RectangleShape pipe_1;
    extern sf::RectangleShape pipe_2;
    extern sf::RectangleShape bigpipe_l;
    extern sf::RectangleShape bigpipe_2;

    // platfroms
    extern sf::Texture t_platform4;
    extern sf::Texture t_platform_6;
    extern sf::Texture t_platform16;
    extern sf::Texture t_platform14;
    extern sf::RectangleShape platform_1;
    extern sf::RectangleShape platform_2;
    extern sf::RectangleShape platform_3;
    extern sf::RectangleShape platform_4;
    extern sf::RectangleShape platform_5;
    extern sf::RectangleShape platform_6;
    extern sf::RectangleShape platform_7;


    void initGround();
    void renderGround(sf::RenderWindow& window);