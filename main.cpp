#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    Window window(VideoMode(800, 600), "Tutorial");

    Event event; // NOLINT(cppcoreguidelines-pro-type-member-init)
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
    }

    return EXIT_SUCCESS;
}