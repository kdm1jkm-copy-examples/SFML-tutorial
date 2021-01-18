//
// Created by user on 2021-01-18.
//

#include "Game.h"

void Game::pushState(GameState *state) {
    states.push(state);
}

void Game::popState() {
    delete states.top();
    states.pop();
}

void Game::changeState(GameState *state) {
    if (!states.empty()) {
        popState();
    }
    pushState(state);
}

GameState *Game::peekState() {
    if (states.empty()) return nullptr;
    return states.top();
}

void Game::gameLoop() {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        if (peekState() == nullptr) continue;

        peekState()->handleInput();
        peekState()->update(elapsed);
        peekState()->draw(elapsed);
    }
}

Game::Game() { // NOLINT(cppcoreguidelines-pro-type-member-init)
    window.create(sf::VideoMode(1280, 720), "SFML Tutorial");
    window.setFramerateLimit(60);
}

Game::~Game() {
    while (!states.empty()) popState();
}

