//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP
#include <string>
#include "../Game.hpp"


class Achievement {
protected:
    void drawFromPNG(const std::string& filename);
public:
    virtual ~Achievement() = default;

    std::string name;
    std::string description;
    bool achieved = false;

    Achievement(const std::string& name, const std::string& description):name(name),description(description) {};
    virtual void check(const Game &game){};
};



#endif //ACHIEVEMENT_HPP
