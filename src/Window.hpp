//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>

#include "Game.hpp"

enum context {
    SPLASH_SCREEN,
    GAME,
    STORE
};

class Window {
    ftxui::Canvas cookieCanvas = ftxui::Canvas(100, 100);
    Game *game = nullptr;
    context currentContext = SPLASH_SCREEN;
    ftxui::Screen screen;
    std::unordered_map<std::string, ftxui::Element> documents;

    void drawDocuments();


public:
    Window(Game &game);
    void render();
    void setContext(context newContext) {;
        currentContext = newContext;
    }


};



#endif //WINDOW_HPP
