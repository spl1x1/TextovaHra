//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Window.hpp"

#include <iomanip>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>


using namespace ftxui;

void Window::quit() {
    system("clear");

    auto exitScreen = vbox(
    text("Děkujeme za hraní ultimátního cookie clickeru!") | center | bold | color(Color::Blue) ,
    text("Váš celkový počet cookies: " + std::to_string(static_cast<int>(game->allTimeCookies))) | center,
    canvas(cookieCanvas) | center
) | border;


    Render(screen, exitScreen);
    screen.Print();

}


void Window::render() {
    game->cookieMutex.lock();


    // Store

    auto ItemComponent = [](const Item &item) -> Component {
        return Container::Horizontal({
            Checkbox( item.name, item.selected) | center,
            Renderer([&] {
                return hbox(
                    canvas(item.itemCanvas),
                    text(" Cost: " + std::to_string(item.baseCost * (item.amount+1))) | center
                    );
            }) | center ,
        }) | border | xflex;
    };

    std::vector<Element> output;
    auto buildings = Container::Vertical({
        ItemComponent (game->Buildings[0]),
        ItemComponent (game->Buildings[1]),
        Button ("Buy", [&] {
            output.clear();
            for (auto &item : game->Buildings) {
                if (*item.selected) {
                    if (game->cookies < item.baseCost * (item.amount + 1)) {
                        output.push_back(text("Not enough cookies for " + item.name + "!") | color(Color::Red) | center);
                        continue;
                    }
                    game->cookies -= item.baseCost * (item.amount + 1);
                    item.amount += 1;
                    game->update();
                    output.push_back(text("Bought 1 " + item.name + "!") | color(Color::Green) | center);
                }
            }
        }),
        Renderer([&] {
            return vbox(output);
            })
        });

    auto upgrades = Container::Vertical({
        //ItemComponent(game->Upgrades[0]),
        //ItemComponent(game->Upgrades[1]),
        Button ("Buy", [&] {

        })

    });


    auto buildingCollapsible = Collapsible("Buildings", buildings);
    auto upgradeCollapsible = Collapsible("Upgrades", upgrades);


    auto buttons = Container::Horizontal({
        buildingCollapsible | border,
        upgradeCollapsible | border
    }) | flex
;
    auto cookiePanel = Container::Vertical({
        Renderer([&] { return vbox(
        text("Ultimátní cookie clicker!") | center | bold | color(Color::Blue),
        separator(),
        text("Level: " + std::to_string(game->level)) | center,
        border(gauge(game->progress)) | border | xflex,
        text("Cookies: " + std::to_string(static_cast<int>(game->cookies))) | center,
        text("All time cookies: " + std::to_string(static_cast<int>(game->allTimeCookies))) | center,
        text("CPS: " + std::to_string(game->cps) + " cookies/second") | center,
        text("Click Power: " + std::to_string(game->clickPower) + " cookies/click") | center,
        text("Auto Click: " + std::to_string(game->autoClick) + " cookies/2 seconds") | center
        ) | border; }),
        Button("Exit", [&] {
    game->running = false;
    screen.ExitLoopClosure()();
    }) | xflex
    });

    auto cookie_renderer = Renderer([&] {
        return canvas(cookieCanvas) | center | border | notflex;
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
        cookiePanel,
        mouseEvent,
        buttons
    });


    game->cookieMutex.unlock();
    screen.Loop(gameComponent);

}

Window::Window(Game *game) : screen(ftxui::ScreenInteractive::FixedSize(140,25)) {
    this->game = game;
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
        text("Press any key to start...") | center,
        canvas(cookieCanvas) | center
    ) | border;



    Render(screen, splashScreen);

    screen.Print();
}
