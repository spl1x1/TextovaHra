//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP
#include <string>


class Game;

class Achievement {
public:
    virtual ~Achievement() = default;

    std::string description;
    bool achieved = false;

    int goal = 0;

    Achievement(const std::string& description, const int goal) : description(description), goal(goal) {};
    void check(Game *game);
};

class TestA : public Achievement {
    public:
    TestA() : Achievement("Get 10 Cookies.", 10) {
        goal = 10;
    }
};



#endif //ACHIEVEMENT_HPP
