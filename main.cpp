#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {
    Window window(VideoMode(800, 600), "Tutorial");

    // NEVER USE BOTH.
    // run at the same frequency as the monitor's refresh rate.
//    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);

    Event event; // NOLINT(cppcoreguidelines-pro-type-member-init)
    Clock clock;
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

        Time elapsed = clock.restart();

        std::cout << elapsed.asSeconds() << std::endl;
    }

    return EXIT_SUCCESS;
}