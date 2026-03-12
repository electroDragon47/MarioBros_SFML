#include "enemy.h"

Enemy::Enemy()
{
    if (!texture.loadFromFile("assets/shellcreeper.png"))
        std::cout << "enemy.png not found\n";
    sprite.setTexture(&texture);
    sprite.setPosition({0, 0});
    sprite.setSize({32,32});
    sprite.setScale({1,1});
    sprite.setOrigin({16,0});
    
    speed = 80.f;
    velocity.x =  speed;
    velocity.y = 0.f;
    gravity = 980.f;
}

void Enemy::update(sf::RenderWindow& window,float dt)
{
    
if(sprite.getPosition().y >= (160-32) &&  sprite.getPosition().y < 132 && sprite.getPosition().x < (16*14) && sprite.getPosition().x > 0){velocity.y = 0;std::cout << "1\n";}
else if(sprite.getPosition().y >= (256-32) &&  sprite.getPosition().y < 230 && sprite.getPosition().x < (128+(16*16))&& sprite.getPosition().x > 128){velocity.y = 0;std::cout << "2\n";} // 128, (272 - 16)
else if(sprite.getPosition().y >= (352-32) && (sprite.getPosition().x < 320 +(16*12) && sprite.getPosition().x > 320.f)){velocity.y = 0;std::cout << "3\n";} //(512 - 192), 352}
else if(sprite.getPosition().y >= (480-64)){velocity.y = 0;std::cout << "ground\n";} //(512 - 192), 352}
else velocity.y += gravity * dt;
sprite.move({velocity.x*dt,velocity.y*dt});


if(sprite.getPosition().x >= 496.f) {
    velocity.x = -speed;
    sprite.setScale({-1,1});
} 
else if(sprite.getPosition().x < 16)
{
    velocity.x = speed;
    sprite.setScale({1,1});
}


window.draw(sprite);
}
