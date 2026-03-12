#include "ground.h"

sf::Texture t_ground;
sf::RectangleShape ground;

sf::Texture smallPipe;
sf::Texture bigpipe;
sf::RectangleShape pipe_1;
sf::RectangleShape pipe_2;
sf::RectangleShape bigpipe_l;
sf::RectangleShape bigpipe_2;

sf::Texture t_platform4;
sf::Texture t_platform_6;
sf::Texture t_platform16;
sf::Texture t_platform14;
sf::RectangleShape platform_1;
sf::RectangleShape platform_2;
sf::RectangleShape platform_3;
sf::RectangleShape platform_4;
sf::RectangleShape platform_5;
sf::RectangleShape platform_6;
sf::RectangleShape platform_7;

void initGround()
{
    //  “You should check whether load from file function succeeded.” becoz its marked as  [[nodiscard]]
    if (!t_ground.loadFromFile("assets/ground.png"))
        std::cout << "asset not loaded\n";

    if (!smallPipe.loadFromFile("assets/pipe_1.png"))
        std::cout << "no pipe_1.png found\n";

    if (!t_platform_6.loadFromFile("assets/platform_6.png"))
        std::cout << "no pipe_1.png found\n";

    if (!t_platform4.loadFromFile("assets/platform4.png"))
    {
        std::cout << "no pipe_1.png found\n";
    }
    if (!t_platform16.loadFromFile("assets/platform16.png"))
    {
        std::cout << "no pipe_1.png found\n";
    }
    if (!t_platform14.loadFromFile("assets/platform14.png"))
    {
        std::cout << "no pipe_1.png found\n";
    }
    if (!bigpipe.loadFromFile("assets/bigpipe.png"))
    {
        std::cout << "no pipe_1.png found\n";
    }

    ground.setTexture(&t_ground);
    ground.setSize({512, 32}); // image is 256 * 16 but double it
    ground.setPosition({0, 448});

    // pipe
    pipe_1.setTexture(&smallPipe);
    pipe_1.setSize({62, 36}); // 31 * 18
    pipe_1.setPosition({62, (480 - 82)});
    pipe_1.setScale({-1, 1});

    // pipe2
    pipe_2.setTexture(&smallPipe);
    pipe_2.setSize({62, 36}); // 31 * 18
    pipe_2.setPosition({(512 - 62), (480 - 82)});

    // big pipe
    bigpipe_l.setTexture(&bigpipe);
    bigpipe_l.setSize({96, 60});
    bigpipe_l.setPosition({0, 84});

    bigpipe_2.setTexture(&bigpipe);
    bigpipe_2.setSize({96, 60});
    bigpipe_2.setPosition({512, 84});
    bigpipe_2.setScale({-1, 1});

    // platform
    platform_1.setTexture(&t_platform14);
    platform_1.setSize({224, 16});
    platform_1.setPosition({0, 160});
    platform_2.setTexture(&t_platform14);
    platform_2.setSize({224, 16});
    platform_2.setPosition({(512 - 224), (272 - 112)});
    platform_3.setTexture(&t_platform16);
    platform_3.setSize({256, 16});
    platform_3.setPosition({128, (272 - 16)});
    platform_4.setTexture(&t_platform4);
    platform_4.setSize({64, 16});
    platform_4.setPosition({0, (352 - 80)});
    platform_5.setTexture(&t_platform4);
    platform_5.setSize({65, 16});
    platform_5.setPosition({(512 - 64), (352 - 80)});
    platform_6.setTexture(&t_platform_6);
    platform_6.setSize({192, 16});
    platform_6.setPosition({0, 352});
    platform_7.setTexture(&t_platform_6);
    platform_7.setSize({192, 16});
    platform_7.setPosition({320, 352});
}

void renderGround(sf::RenderWindow &window)
{
    window.draw(ground);
    // window.draw(ground_1);
    window.draw(pipe_1);
    window.draw(pipe_2);
    window.draw(bigpipe_2);
    window.draw(bigpipe_l);
    window.draw(platform_1);
    window.draw(platform_2);
    window.draw(platform_3);
    window.draw(platform_4);
    window.draw(platform_5);
    window.draw(platform_6);
    window.draw(platform_7);
}