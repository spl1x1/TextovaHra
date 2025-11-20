//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <ftxui/dom/canvas.hpp>


using namespace ftxui;

class Item {
protected:
    void drawFromPNG(const std::string& filename);
public:
    std::string displayName;
    std::string name;
    int baseCost;
    int amount = 0;
    double clickPower;
    double cps;
    Canvas itemCanvas = Canvas(16, 16);

    std::string description;

    Item(const std::string& name, int baseCost, double cps, double clickPower);
    void setDisplayName(const std::string& name);
    void setDescription(const std::string& desc);
};



#endif //ITEM_HPP
