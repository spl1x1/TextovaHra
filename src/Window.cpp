//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Window.hpp"

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

void Window::quit() {
    system("clear");

    auto exitScreen = vbox(
    text("Děkujeme za hraní ultimátního cookie clickeru!") | center | bold | color(Color::Blue) ,
    separator() ,
    canvas(cookieCanvas) | center,
    separator(),
    text("Váš konečný počet cookies: " + std::to_string(game->cookies)) | center
) | border;


    Render(screen, exitScreen);
    screen.Print();

}


void Window::render() {
    game->cookieMutex.lock();

    bool showStore = false;

    CheckboxOption storeOption1;
    CheckboxOption storeOption2;
    CheckboxOption storeOption3;

    storeOption1.label = "x: " + std::to_string(screen.dimx());
    storeOption2.label = "y: " + std::to_string(screen.dimx());
    storeOption3.label = "Mega Cookie";

    storeOption1.checked = false;
    storeOption2.checked = false;
    storeOption3.checked = false;

    auto store = Container::Vertical({
        Checkbox(storeOption1),
        Checkbox(storeOption2),
        Checkbox(storeOption3),
        Button ("Buy", [&] {
        })});
    auto storeMaybe = Maybe(store, &showStore);


    auto buttons = Container::Vertical({
        Button("Store", [&] {
            showStore = !showStore;
        }),
        storeMaybe,
        Button("Exit", [&] {
            game->running = false;
            screen.ExitLoopClosure()();
        }),
    });

    auto renderer = Renderer([&] { return vbox(
        text("Ultimátní cookie clicker!") | center | bold | color(Color::Blue),
        separator(),
        text("Level: " + std::to_string(game->level)) | center,
        border(gauge(game->progress)) | border | xflex,
        text("Cookies: " + std::to_string(game->cookies)) | center,
        text("CPS: " + std::to_string(game->cps) + " cookies/second") | center,
        text("Mouse x: " + std::to_string(mouse_x)) | center,
        text("Mouse y: " + std::to_string(mouse_y)) | center
        ) | border; });

    auto cookie_renderer = Renderer([&] {
        return canvas(cookieCanvas) | center | border ;
    });


    auto mouseEvent = CatchEvent(cookie_renderer, [&](Event event)-> bool {
        mouse_x = event.mouse().x;
        mouse_y = event.mouse().y;
        if (!event.is_mouse()) return false;
        if (event.mouse().button != Mouse::Left || event.mouse().motion > 0)return false;
        if (event.mouse().x < 45 || event.mouse().x > 66) return false;
        if (event.mouse().y < 8 || event.mouse().y > 19) return false;
        game->click();
        return true;
    });

    auto gameComponent = Container::Horizontal({
        renderer,
        mouseEvent,
        buttons
    });


    game->cookieMutex.unlock();
    screen.Loop(gameComponent);

}

Window::Window(Game &game) : screen(ftxui::ScreenInteractive::FixedSize(140,25)) {
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
