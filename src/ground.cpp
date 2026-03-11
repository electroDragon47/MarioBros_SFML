#include "ground.h"

sf::Texture t_ground;
sf::RectangleShape ground;

sf::Texture t_ground_1;
sf::RectangleShape ground_1;

sf::Texture t_pipe_1;
sf::RectangleShape pipe_1;

sf::RectangleShape pipe_2;

void initGround()
{
    if (!t_ground.loadFromFile("assets/ground.png")) //  “You should check whether load from file function succeeded.” becoz its marked as  [[nodiscard]]
    {
        std::cout << "not found ground.png\n";
    }

    if (!t_ground_1.loadFromFile("assets/ground_1.png"))
    {
        std::cout << "no found ground_1.png\n";
    }

    if(!t_pipe_1.loadFromFile("assets/pipe_1.png"))
    {
        std::cout << "no pipe_1.png found\n";
    }

    ground.setTexture(&t_ground);
    ground.setSize({512, 32}); // image is 256 * 16 but double it
    ground.setPosition({0, 448});

    // single ground time
    ground_1.setTexture(&t_ground_1);
    ground_1.setSize({32, 32});
    ground_1.setPosition({(32*3),352});

    // pipe
    pipe_1.setTexture(&t_pipe_1);
    pipe_1.setSize({62,36}); // 31 * 18
    pipe_1.setPosition({62, (480-82)});
    pipe_1.setScale({-1,1});

    // pipe2
    pipe_2.setTexture(&t_pipe_1);
    pipe_2.setSize({62,36}); // 31 * 18
    pipe_2.setPosition({(512-62), (480-82)});

}

void renderGround(sf::RenderWindow &window)
{
    window.draw(ground);
    window.draw(ground_1);
    window.draw(pipe_1);
    window.draw(pipe_2);
}