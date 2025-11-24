//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef GAME_HPP
#define GAME_HPP


#include <mutex>
#include <thread>
#include <vector>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>


#include "Achievements/Achievement.hpp"
#include "Items/Item.hpp"

class Game {
    void gameLoop();
    ScreenInteractive *screen = nullptr;

public:
    bool running = true;

    std::thread cookieThread;
    std::mutex cookieMutex;

    double cookies = 0;
    double allTimeCookies = 0;

    double cps = 0.0;
    double clickPower = 1.0;
    double autoClick = 0.0;

    int level = 1;
    float progress = 0.0;
    float levelDifficulty = 2.0;
    double progressMultiplier = 0.1;

    std::vector<Item> Buildings;
    std::vector<Item> Upgrades;
    std::vector<Achievement> Achievements;

    void update();
    void click();
    void initCookie(ScreenInteractive* screen);

    ~Game() {
        running = false;
        if (cookieThread.joinable()) {
            cookieThread.join();
        }
    }
};



#endif //GAME_HPP
