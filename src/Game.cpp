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

void Game::initCookie(ScreenInteractive& screen) {
    Buildings.push_back(Cursor());
    Buildings.push_back(Factory());

    cookieThread = std::thread(&Game::gameLoop, this, std::ref(screen));

}

void Game::click() {
    if (progress >= 1.0) {
        level += 1;
        progress = 0.0;
        levelDifficulty = exp(levelDifficulty);
    }
    progress += 0.1f/levelDifficulty * progressMultiplier;


    cookies += clickPower;
    allTimeCookies += clickPower;
}

void Game::gameLoop(ScreenInteractive &screen) {
    double lastCookieCount = 0;
    while (running) {
        using namespace std::chrono_literals;
        const auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(2000ms);
        cookieMutex.lock();
        cps = (allTimeCookies - lastCookieCount) / 2.0;
        const auto end = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> deltaTime = end - start;

        double deltaCookies = autoClick * (deltaTime.count() / 1000.0);
        cookies += deltaCookies;
        allTimeCookies += deltaCookies;
        lastCookieCount = allTimeCookies;
        cookieMutex.unlock();
        screen.PostEvent(Event::Custom);
    }
}