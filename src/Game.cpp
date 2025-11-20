//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Game.hpp"

#include "Items/Cursor.hpp"
#include "Items/Factory.hpp"

void Game::update() {
    cookieMutex.lock();
    autoClick = 0.0;
    clickPower = 1.0;
    for (const auto &item : Buildings) {
        for (int i = 0; i < item.amount; i++) {
            autoClick += item.cps;
            clickPower += item.clickPower;
        }
    }
    for (const auto &item : Upgrades) {
        for (int i = 0; i < item.amount; i++) {
            autoClick += item.cps;
            clickPower += item.clickPower;
        }
    }
    cookieMutex.unlock();
}

void Game::initCookie() {
    Buildings.push_back(Cursor());
    Buildings.push_back(Factory());

    cookieThread = std::thread(&Game::gameLoop, this);

}

void Game::click() {
    if (progress >= 1.0) {
        level += 1;
        progress = 0.0;
        levelDifficulty = exp(levelDifficulty);
    }
    progress += 0.1f/levelDifficulty * progressMultiplier;


    cookieProgress += clickPower;
    cookies += static_cast<int>(cookieProgress);
    allTimeCookies += static_cast<int>(cookieProgress);
    cookieProgress -= static_cast<int>(cookieProgress);
}

void Game::gameLoop() {
    if (!running) return;
    using namespace std::chrono_literals;

    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2000ms);
    cookieMutex.lock();
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> deltaTime = end - start;

    cookieProgress += autoClick * (deltaTime.count() / 1000.0);
    int deltaCookies = static_cast<int>(cookieProgress);
    cookies += deltaCookies;
    allTimeCookies += deltaCookies;
    cookieProgress -= deltaCookies;
    cookieMutex.unlock();
}