//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Window.hpp"

#include <iomanip>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

#include "Achievements/Achievement.hpp"


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
    auto ItemComponent = [&](const Item &item) -> Component {
        return Container::Horizontal({
            Checkbox( item.name, item.selected) | center,
            Renderer([&] {
                auto itemText = vbox(
                    text(" Cost: " + std::to_string(item.baseCost * (item.amount+1))) | center,
                    text (" Amount: " + std::to_string(item.amount)) | center,
                    text(" Req. Level: " + std::to_string(item.requiredLevel)) | center,
                    text(" CPS: " + std::to_string(item.cps)) | center,
                    text(" Click Power: " + std::to_string(item.clickPower)) | center
                );
                auto box = hbox(
                    canvas(item.itemCanvas),
                    itemText
                    );
                if (game->level < item .requiredLevel) {
                    return box | color(Color::Red) | dim ;
                }
                if (game->cookies < item.baseCost * (item.amount + 1)) {
                    return box | color(Color::Yellow) | dim ;
                }
                return box | color(Color::Green) ;
            }) | center ,
        }) | border | xflex;
    };

    std::vector<Element> output;
    auto buyButton =[&] (std::vector<Item>& itemList)->Component {
        return Button("Buy", [&] {
            output.clear();
            for (auto &item : itemList) {
                if (*item.selected) {
                if (game->level < item.requiredLevel) {
                output.push_back(text("Level too low for " + item.name + "!") | color(Color::Red) | center);
                continue;
                }
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
        });
    };

    int selectedItemPage = 0;

    auto itemComponents = [&](std::vector<Item>& itemList) -> Components {
        ;
        auto components = Components();
        auto buttons = Components();
        auto itemTabs = Components();
        int pageItems = 3;

        int pageCount = std::ceil(static_cast<double>(itemList.size()) / pageItems);

        for (int page = 0; page < pageCount; page++) {
            auto list = std::vector<Item>(
                itemList.begin() + page * pageItems,
                itemList.begin() + std::min(static_cast<size_t>((page + 1) * pageItems), itemList.size())
            );
            buttons.push_back(
                Button(std::to_string(page + 1), [&selectedItemPage, page] {
                    selectedItemPage = page;
                })
            );

            auto pageComponents = Components();
            for (size_t i = page * pageItems; i < std::min(static_cast<size_t>((page + 1) * pageItems), itemList.size()); ++i) {
                pageComponents.push_back(ItemComponent(itemList[i]));
            }

            itemTabs.push_back(
                Container::Vertical(std::move(pageComponents))
            );
        }

        components.push_back(Container::Horizontal(std::move(buttons)) | flex);
        components.push_back(Container::Tab(std::move(itemTabs), &selectedItemPage));
        components.push_back(std::move(buyButton(itemList)));
        components.push_back(
            Renderer([&] {
                return vbox(output);
            }));
        return components;
    };


    auto AchievementComponent = [&](const Achievement &achievement) -> Component {
            return Renderer([&] {
                if (!achievement.achieved) {
                    return text(achievement.description) | center | border | color(Color::Red) | dim ;
                }
                return text(achievement.description) | center | border | color(Color::Green) ;
            });
    };

    int selectedAchievementPage = 0;

    auto achievementComponents = [&](std::vector<Achievement>& achievementList) -> Components {
        int pageItems = 6;
        auto components = Components();
        auto buttons = Components();

        int pageCount = ceil(static_cast<double>(achievementList.size()) / pageItems);

        for (int page = 0; page < pageCount; page++) {
            auto list = std::vector<Achievement>(
                achievementList.begin() + page * pageItems,
                achievementList.begin() + std::min(static_cast<size_t>((page + 1) * pageItems), achievementList.size())
            );
            buttons.push_back(
                Button(std::to_string(page + 1), [&selectedAchievementPage, page] {
                    selectedAchievementPage = page;
                })
            );

            auto pageComponents = Components();
            for (size_t i = page * pageItems; i < std::min(static_cast<size_t>((page + 1) * pageItems), achievementList.size()); ++i) {
                pageComponents.push_back(AchievementComponent(achievementList[i]));
            }

            components.push_back(
                Container::Vertical(std::move(pageComponents))
            );
        }

        auto result = Components();
        result.push_back(Container::Horizontal(std::move(buttons)) | flex);
        result.push_back(Container::Tab(std::move(components), &selectedAchievementPage));
        return result;
    };



    int tab_selected = 0;

    std::vector<std::string> tab_names = {
        "Buildings",
        "Upgrades",
        "Achievements"
    };

    auto buttons = Container::Tab({
        Container::Vertical(itemComponents(game->Buildings)),
        Container::Vertical(itemComponents(game->Upgrades)),
        Container::Vertical(achievementComponents(game->Achievements))
    } , &tab_selected) | xflex;

    auto store = Container::Vertical({
        Toggle(tab_names, &tab_selected) | border,
        buttons
    });
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
        text("Auto Click: " + std::to_string(game->autoClick) + " cookies/seconds") | center
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
        if (event.mouse().x < 60 || event.mouse().x > 80) return false;
        if (event.mouse().y < 8 || event.mouse().y > 19) return false;
        game->click();
        return true;
    });

    auto gameComponent = Container::Horizontal({
        cookiePanel |  size(WIDTH, EQUAL, 40),
        mouseEvent |  size(WIDTH, EQUAL, 60),
        store |  size(WIDTH, EQUAL, 40)
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
