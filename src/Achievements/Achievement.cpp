//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#include "Achievement.hpp"
#include "../Game.hpp"


void Achievement::check(Game *game) {
    if (achieved) return;
    switch (type) {
        case LEVEL:{ if (game->level >= goal) achieved = true; break;}
        case ALLTIMECOOKIE:{ if (game->allTimeCookies >= goal) achieved = true; break;}
        case COOKIECOUNT:{ if (game->cookies >= goal) achieved = true; break;}
        case BUILDINGCOUNT:{ if (game->Buildings.at(goal).amount >= count) achieved = true; break;}
        case UPGRADECOUNT:{ if (game->Upgrades.at(goal).amount >= count) achieved = true; break;}
        case CPS:{ if (game->cps >= goal) achieved = true; break;}
        case CP:{ if (game->clickPower >= goal) achieved = true; break;}

    }
}