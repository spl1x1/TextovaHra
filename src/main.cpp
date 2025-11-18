#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

int main() {
    Game game;
    Window window(game);

    window.render();
    std::cin.get();
    window.setContext(GAME);
    window.render();
    game.initCookie();

    while (game.running) {
        window.render();
    }

    return 0;
}