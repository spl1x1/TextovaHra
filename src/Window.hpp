//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/canvas.hpp>


#include "Game.hpp"

class Window {
    int mouse_x = 0;
    int mouse_y = 0;


    Canvas cookieCanvas = Canvas(100, 100);
    Game *game = nullptr;

public:
    ScreenInteractive screen;

    explicit Window(Game *game);
    void render();

    void quit();
};



#endif //WINDOW_HPP
