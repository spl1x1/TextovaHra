#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

int main() {
    Game game;
    Window window(game);

    std::cin.get();
    game.initCookie();

    while (game.running) {
        window.render();
    }

    return 0;
}