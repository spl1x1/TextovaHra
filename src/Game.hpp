//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <mutex>
#include <thread>
#include <vector>

#include "Item.hpp"


class Game {
    void gameLoop();

public:
    bool running = true;

    std::thread cookieThread;
    std::mutex cookieMutex;

    int cookies = 0;
    double cookieProgress = 0.0;


    double cps = 0.0;
    double clickPower = 1.0;
    double autoClick = 0.0;

    int level = 1;
    float progress = 0.0;
    double progressMultiplier = 0.1;

    std::vector<Item> Items;

    void update();
    void click();
    void initCookie() {
        cookieThread = std::thread(&Game::gameLoop, this);
    }
};



#endif //GAME_HPP
