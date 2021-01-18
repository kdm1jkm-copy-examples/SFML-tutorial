#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


int main() {
    // Files
    const std::string BALL_TEXTURE_DIRECTORY("resources/example_ball-Sheet.png");
    const std::string FONT_DIRECTORY("resources/NanumGothic.ttf");

    // New window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tutorial");

    // For animating
    sf::Time time = sf::milliseconds(0);
    int sheet = 0;
    const sf::Time interval = sf::milliseconds(100);
    const int sheets = 2;

    // Load texture
    sf::Texture ballTexture;
    if (!(ballTexture.loadFromFile(BALL_TEXTURE_DIRECTORY, sf::Rect<int>(0, 0, 16, 8)))) {
        return EXIT_FAILURE;
    }
    // Anti-aliasing
//    ballTexture.setSmooth(true);

    // Make sprite
    sf::Sprite ballSprite(ballTexture, sf::IntRect(8, 0, 8, 8));
    ballSprite.setPosition(sf::Vector2f(100, 100));
    ballSprite.setScale(sf::Vector2f(5, 5));

    // NEVER USE BOTH.
    // run at the same frequency as the monitor's refresh rate.
//    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);

    // Main loop
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

        // Animate
        if (time > interval) {
            ballSprite.setTextureRect(sf::IntRect(8 * sheet, 0, 8, 8));

            sheet++;
            if (sheet >= sheets) sheet = 0;
            time = sf::milliseconds(0);
        }

        // Draw things
        window.draw(ballSprite);

        sf::Time elapsed = clock.restart();
        time += elapsed;
//        std::cout << elapsed.asSeconds() << std::endl;

        window.display();
    }

    return EXIT_SUCCESS;
}
