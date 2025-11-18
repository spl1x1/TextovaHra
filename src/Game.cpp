//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Game.hpp"

void Game::update() {

}


void Game::click() {
    if (progress >= 1.0) {
        level += 1;
        progress = 0.0;
    }
    progress += 0.1;
}

void Game::gameLoop() {
    if (!running) return;
    using namespace std::chrono_literals;

    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2000ms);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> deltaTime = end - start;

    cookieMutex.lock();
    cookieProgress += autoClick * (deltaTime.count() / 1000.0);
    int deltaCookies = static_cast<int>(cookieProgress);
    cookies += deltaCookies;
    cookieProgress -= deltaCookies;
    cookieMutex.unlock();
}