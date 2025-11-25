//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP
#include <string>
#include <utility>


class Game;


class Achievement {
public:
    enum AchievementType {
        LEVEL,
        ALLTIMECOOKIE,
        COOKIECOUNT,
        BUILDINGCOUNT,
        UPGRADECOUNT,
        CPS,
        CP
    };

    virtual ~Achievement() = default;

    std::string description;
    bool achieved = false;

    int goal = 0;
    int count;
    AchievementType type;


    Achievement(std::string  description, AchievementType type, const int goal, int count = 0) : description(std::move(description)), type(type) ,goal(goal), count(count){}
    void check(Game *game);

    static Achievement CookieMilestone(int cookieCount) {
        return {"Get " + std::to_string(cookieCount) + " cookies", Achievement::ALLTIMECOOKIE, cookieCount};
    }

    static Achievement LevelMilestone(int level) {
        return {"Reach level " + std::to_string(level), Achievement::LEVEL, level};
    }

    static Achievement CookiesInBankMilestone(int cookieCount) {
        return {"Hold more than " + std::to_string(cookieCount) + " cookies", Achievement::COOKIECOUNT, cookieCount};
    }

    static Achievement CPSMilestone(int cps) {
        return {"Reach CPS of more than " + std::to_string(cps), Achievement::CPS, cps};
    }

    static Achievement CPMilestone(int cp) {
        return {"Reach CP of more than " + std::to_string(cp), Achievement::CP, cp};
    }
};

#endif //ACHIEVEMENT_HPP
