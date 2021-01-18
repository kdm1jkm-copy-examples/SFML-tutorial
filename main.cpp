#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


int main() {
    const std::string BALL_TEXTURE_DIRECTORY("resources/example_ball-Sheet.png");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Tutorial");

    sf::Time time = sf::milliseconds(0);
    int sheet = 0;
    const sf::Time interval = sf::milliseconds(100);
    const int sheets = 2;

    sf::Texture ballTexture;
    ballTexture.loadFromFile(BALL_TEXTURE_DIRECTORY, sf::Rect<int>(0, 0, 16, 8));

    sf::Sprite ballSprite(ballTexture, sf::IntRect(8, 0, 8, 8));
    ballSprite.setPosition(sf::Vector2f(100, 100));
    ballSprite.setScale(sf::Vector2f(5, 5));

    // NEVER USE BOTH.
    // run at the same frequency as the monitor's refresh rate.
//    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);

    sf::Event event; // NOLINT(cppcoreguidelines-pro-type-member-init)
    sf::Clock clock;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }
        window.clear(sf::Color::Green);

        if (time > interval) {
            ballSprite.setTextureRect(sf::IntRect(8 * sheet, 0, 8, 8));

            sheet++;
            if (sheet >= sheets) sheet = 0;
            time = sf::milliseconds(0);
        }

        window.draw(ballSprite);

        // Handle event
        sf::Time elapsed = clock.restart();
        time += elapsed;
//        std::cout << elapsed.asSeconds() << std::endl;

        window.display();
    }

    return EXIT_SUCCESS;
}
