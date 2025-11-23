//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP
#include <string>
#include "../Game.hpp"
#include <ftxui/dom/canvas.hpp>


class Achievement {
public:
    virtual ~Achievement() = default;

    std::string displayName;
    std::string name;
    std::string description;
    bool achieved = false;
    Canvas achievementCanvas;

    Achievement(const std::string& name, const std::string& description, const std::string& displayName = "");
    virtual void check(const Game &game){};
};



#endif //ACHIEVEMENT_HPP
