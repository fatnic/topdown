#include <SFML/Graphics.hpp>

int main()
{
    bool moveUp    = false;
    bool moveDown  = false;
    bool moveLeft  = false;
    bool moveRight = false;

    bool boost = false;

    float speed = 2.f;

    sf::Color bgColour(64,64,64);

    sf::RenderWindow window(sf::VideoMode(1024, 600), "GameWindow");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("assets/theguy.png");

    sf::Sprite sprite(texture);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    sprite.setPosition(window.getSize().x/2, window.getSize().y/2);
    sprite.setScale(.75f, .75f);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type){

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A)
                    moveLeft = true;
                else if (event.key.code == sf::Keyboard::W)
                    moveUp = true;
                else if (event.key.code == sf::Keyboard::D)
                    moveRight = true;
                else if (event.key.code == sf::Keyboard::S)
                    moveDown = true;
                else if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
                    boost = true;
                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::A)
                    moveLeft = false;
                else if (event.key.code == sf::Keyboard::W)
                    moveUp = false;
                else if (event.key.code == sf::Keyboard::D)
                    moveRight = false;
                else if (event.key.code == sf::Keyboard::S)
                    moveDown = false;
                else if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
                    boost = false;
                break;

            case sf::Event::Closed:
                window.close();
                break;

            default: break;
            }
        }

        speed = (boost) ? 4.f : 2.f;

        if (moveUp && moveRight)
        {
            sprite.move(speed,-speed);
            sprite.setRotation(45);
        }
        else if (moveDown && moveRight)
        {
            sprite.move(speed,speed);
            sprite.setRotation(135);
        }
        else if (moveDown && moveLeft)
        {
            sprite.move(-speed,speed);
            sprite.setRotation(225);
        }
        else if (moveUp && moveLeft)
        {
            sprite.move(-speed,-speed);
            sprite.setRotation(-45);
        }
        else if (moveLeft)
        {
            sprite.move(-speed,0);
            sprite.setRotation(-90);
        }
        else if (moveDown)
        {
            sprite.move(0,speed);
            sprite.setRotation(180);
        }
        else if (moveRight)
        {
            sprite.move(speed,0);
            sprite.setRotation(90);
        }
        else if (moveUp)
        {
            sprite.move(0,-speed);
            sprite.setRotation(0);
        }


        window.clear(bgColour);
        window.draw(sprite);
        window.display();

    }

    return 0;
}
