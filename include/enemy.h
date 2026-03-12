#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

class Enemy
{
    private:
    sf::Texture texture;
    sf::RectangleShape sprite;
    sf::Vector2f velocity;
    float gravity;
    float speed;

    public:
    Enemy();
    void update(sf::RenderWindow& window,float dt);

};

