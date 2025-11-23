//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#include "Achievement.hpp"

#include "../Utils.hpp"

Achievement::Achievement(const std::string& name, const std::string& displayName, const std::string& description):name(name),description(description) {
    this->displayName = displayName.empty() ? name : displayName;
    Utils::drawFromPNG("assets/achievements/"+name+".png", &achievementCanvas);
}
