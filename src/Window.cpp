//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Window.hpp"

#include <ftxui/dom/elements.hpp>

using namespace ftxui;

void Window::render() {
    drawDocuments();
    screen.Clear();
    switch (currentContext) {
        case SPLASH_SCREEN:
            Render(screen, documents["splash_screen"]);
            break;
        case GAME:
            Render(screen, documents["game"]);
            break;
        case STORE:
            Render(screen, documents["store"]);
            break;
    }
    screen.Print();
}


void Window::drawDocuments() {
    game->cookieMutex.lock();
    auto tlevel = "Level: " + std::to_string(game->level);

    documents["game"] = vbox(
            text("Ultimátní cookie clicker!") | center | bold | color(Color::Blue) ,
            separator() ,
            text(tlevel) | center,
            border(gauge(game->progress))  | xflex,
            canvas(cookieCanvas) | center
    ) | border;    documents["store"] = ftxui::text("Store Screen");
    game->cookieMutex.unlock();
}

Window::Window(Game &game) : screen(ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Full())) {

    this->game = &game;
    // Hlavní tělo cookie (vnější kruh)
    cookieCanvas.DrawPointCircle(50, 50, 20, Color::RGB(210, 180, 140));
    cookieCanvas.DrawPointCircleFilled(50, 50, 20, Color::RGB(210, 180, 140));

    // Čokoládové kousky (maximálně rozptýlené)
    cookieCanvas.DrawPointCircleFilled(40, 40, 3, Color::RGB(101, 67, 33));
    cookieCanvas.DrawPointCircleFilled(60, 43, 2, Color::RGB(101, 67, 33));
    cookieCanvas.DrawPointCircleFilled(53, 60, 3, Color::RGB(101, 67, 33));
    cookieCanvas.DrawPointCircleFilled(43, 57, 2, Color::RGB(101, 67, 33));
    cookieCanvas.DrawPointCircleFilled(58, 54, 2, Color::RGB(101, 67, 33));

    // Okraj cookie
    cookieCanvas.DrawPointCircle(50, 50, 20, Color::RGB(160, 130, 90));

    documents["splash_screen"] = vbox(
        text("Vítej v ultimátním cookie clickeru!") | center | bold | color(Color::Blue) ,
        separator() ,
        text("Press any key to start...") | center,
        canvas(cookieCanvas) | center
) | border;

    drawDocuments();
}
