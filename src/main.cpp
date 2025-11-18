#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

int main() {
    Game game;
    Window window(game);

    std::cin.get();
    game.initCookie();

    window.render();
    window.quit();


    return 0;
}