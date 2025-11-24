#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

int main() {
    Game *game = new Game();
    Window window(game);

    std::cin.get();
    game->initCookie(&window.screen);

    window.render();
    window.quit();
    delete game;


    return 0;
}