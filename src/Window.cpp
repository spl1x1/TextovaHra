//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Window.hpp"

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;


void Window::render() {
    game->cookieMutex.lock();
    auto cLevel = "Level: " + std::to_string(game->level);

    auto part1 = vbox(
    text("Ultimátní cookie clicker!") | center | bold | color(Color::Blue),
    separator(),
    text(cLevel) | center,
    border(gauge(game->progress)) | xflex
) | border;

    auto buttons = Container::Vertical({
        Button("Click me!", [&] {
            game->click();

        }),
        Button("Go to Store", [&] {
        }),
        Button("Exit", [&] {
            game->running = false;
            screen.ExitLoopClosure();
        }),
    });

    auto part2 = vbox(
        canvas(cookieCanvas) | center
    ) | border;

    auto gameComponent = Container::Vertical({
        Renderer([&] { return part1; }),
        Renderer([&] { return part2; }),
        buttons
    });

    game->cookieMutex.unlock();
    screen.Loop(gameComponent);

}

Window::Window(Game &game) : screen(ftxui::ScreenInteractive::Fullscreen()) {
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

    auto splashScreen = vbox(
        text("Vítej v ultimátním cookie clickeru!") | center | bold | color(Color::Blue) ,
        separator() ,
        text("Press any key to start...") | center,
        canvas(cookieCanvas) | center
    ) | border;

    Render(screen, splashScreen);
    screen.Print();
}
