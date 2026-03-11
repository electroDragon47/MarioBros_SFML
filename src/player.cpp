#include "player.h"

Player::Player()
{
    if (!texture.loadFromFile("assets/player.png"))
        std::cout << "faild to load texture\n";

    sprite.setTexture(&texture);
    sprite.setPosition({200, 200});
    sprite.setSize({32, 42});    // will make all sprites 2x so no need to code this again
    sprite.setOrigin({16.f, 0}); // to align fliping

    velocity = {0.f, 0.f};
    acceleration = {0.f, 0.f};
    canMove = true;
    onGround = false;
    maxVelx = 150.f;
    retardation = 500.f;
    gravity = 1200.f;
}

void Player::update(sf::RenderWindow &window, float dt)
{
    if (canMove)
    {
        move(dt);
    }

    // jump with W
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) && onGround)
    {
        velocity.y = -500.f;
        onGround = false;
    }

    // graVity
    if (!onGround)
    {
        velocity.y += gravity * dt;
    }

    if (acceleration.x == 0.f)
    {
        if (velocity.x > 0.f)
        {
            velocity.x -= retardation * dt;
            if (velocity.x < 0.f)
                velocity.x = 0.f;
        }

        else if (velocity.x < 0.f)
        {
            velocity.x += retardation * dt;
            if (velocity.x > 0.f)
                velocity.x = 0.f;
        }
    }

    velocity.x += acceleration.x * dt;
    velocity.x = std::clamp(velocity.x, -maxVelx, maxVelx);

    sprite.move({velocity.x * dt, velocity.y * dt});

    checkIfOnGround();
    if (onGround && velocity.y > 0.f)
    {
        velocity.y = 0.f;
        sprite.setPosition({sprite.getPosition().x, 406.f}); // to prevent floor me sinking player
    }

    window.draw(sprite); // render the SPRITEEEEEEEEEEEEE
}

void Player::move(float dt)
{
    acceleration.x = 0.f; // resets every frame
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)){
        acceleration.x = -800.f;
        sprite.setScale({1,1});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)){
        acceleration.x = 800.f;
        sprite.setScale({-1,1});
    }
}

void Player::checkCollision(sf::RectangleShape object, float dt)
{
    auto intersection = sprite.getGlobalBounds().findIntersection(object.getGlobalBounds());

    if(!intersection){
        return;
    }

    float overlapX = (*intersection).size.x;
    float overlapY = (*intersection).size.y;

    if(overlapX < overlapY)
    {
        if(velocity.x > 0)
            sprite.move({-overlapX,0});
        else
            sprite.move({overlapX,0});

        velocity.x = 0.f;
    }

    else 
    if(velocity.y > 0){
        sprite.move({0,-overlapY});
            onGround = true;
    }        
        else{sprite.move({0,overlapY});}
            

        velocity.y = 0.f;

}

void Player::checkIfOnGround()
{
    onGround = sprite.getPosition().y >= 406.f;
}

