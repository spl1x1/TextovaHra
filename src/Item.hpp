//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <ftxui/dom/canvas.hpp>
#include <utility>


using namespace ftxui;

class Item {
public:
    std::string name;
    int baseCost;
    double clickPower = 0;
    double cps = 0;
    ftxui:: Canvas itemCanvas = ftxui::Canvas(50, 50);


    Item(std::string name, int baseCost, double cps, double clickPower)
            : name(std::move(name)), baseCost(baseCost), cps(cps), clickPower(clickPower) {}
};



#endif //ITEM_HPP
