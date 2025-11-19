//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <mutex>
#include <thread>
#include <vector>

#include "Items/Item.hpp"

struct ownedItem {
    Item item;
    int amount = 0;
};

class Game {
    void gameLoop();

public:
    bool running = true;

    std::thread cookieThread;
    std::mutex cookieMutex;

    int cookies = 0;
    int allTimeCookies = 0;
    double cookieProgress = 0.0;


    double cps = 0.0;
    double clickPower = 1.0;
    double autoClick = 0.0;

    int level = 1;
    float progress = 0.0;
    float levelDifficulty = 2.0;
    double progressMultiplier = 0.1;

    std::vector<ownedItem> Items;

    void update();
    void click();
    void initCookie() {
        cookieThread = std::thread(&Game::gameLoop, this);
    }

    ~Game() {
        running = false;
        if (cookieThread.joinable()) {
            cookieThread.join();
        }
    }
};



#endif //GAME_HPP
