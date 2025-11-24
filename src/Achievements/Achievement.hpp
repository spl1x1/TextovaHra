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

    std::string displayName;
    std::string name;
    std::string description;
    bool achieved = false;

    int goal = 0;

    Achievement(const std::string& name, const std::string& description, std::string  displayName = "");
    void check(Game *game);
};

class TestA : public Achievement {
    public:
    TestA() : Achievement("Test Achievement", "This is a test achievement.", "Test Achievement") {
        goal = 10;
    }
};



#endif //ACHIEVEMENT_HPP
