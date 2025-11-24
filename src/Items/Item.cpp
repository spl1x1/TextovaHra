//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Item.hpp"

#include "../Utils.hpp"

Item::Item(const std::string& name, int baseCost, double cps, double clickPower, int requiredLevel):name(name),baseCost(baseCost), cps(cps), clickPower(clickPower), requiredLevel(requiredLevel)
{
    selected = new bool(false);
    Utils::drawFromPNG("assets/"+name+".png", &itemCanvas);
    displayName = name;
    description = "No description available.";
}


void Item::setDisplayName(const std::string& name) {
    displayName = name;
};
void Item::setDescription(const std::string& desc) {
    description = desc;
}