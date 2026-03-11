#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    sf::Texture texture;
    sf::RectangleShape sprite;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    bool canMove;
    bool onGround;
    float maxVelx;
    float retardation;
    float gravity;



public:
    Player();

    void update(sf::RenderWindow& window, float dt);
    void move(float dt);
    void checkCollision(sf::RectangleShape object, float dt);
    void checkIfOnGround();
};