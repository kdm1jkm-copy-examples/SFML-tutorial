#ifndef SFML_TUTORIAL_GAMESTATE_H
#define SFML_TUTORIAL_GAMESTATE_H

class Game;

class GameState { // NOLINT(cppcoreguidelines-pro-type-member-init)
public:
    Game *game;

    virtual void draw(const sf::Time &dt) = 0;

    virtual void update(const sf::Time &dt) = 0;

    virtual void handleInput() = 0;
};


#endif //SFML_TUTORIAL_GAMESTATE_H
