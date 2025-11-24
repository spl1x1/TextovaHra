//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#include "Achievement.hpp"
#include "../Game.hpp"


void Achievement::check(Game *game) {
    if (achieved) return;
    if (game->allTimeCookies >= goal) {
        achieved = true;
    }
}