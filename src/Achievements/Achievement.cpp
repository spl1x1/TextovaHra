//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#include "Achievement.hpp"
#include "../Game.hpp"

#include <utility>

#include "../Utils.hpp"

Achievement::Achievement(const std::string& name, const std::string& displayName, std::string  description):name(name),description(std::move(description)) {
    this->displayName = displayName.empty() ? name : displayName;
}

void Achievement::check(Game *game) {
    if (achieved) return;
    if (game->allTimeCookies >= goal) {
        achieved = true;
    }
}