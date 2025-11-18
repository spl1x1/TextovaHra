//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef SWORD_HPP
#define SWORD_HPP
#include "../Item.hpp"


class Sword : public Item{

    Sword(): Item("Sword", 100, 0, 0) {

        itemCanvas.DrawPointCircle(50, 50, 20, Color::RGB(210, 180, 140));
        itemCanvas.DrawPointCircleFilled(50, 50, 20, Color::RGB(210, 180, 140));

        // Čokoládové kousky (maximálně rozptýlené)
        itemCanvas.DrawPointCircleFilled(40, 40, 3, Color::RGB(101, 67, 33));
        itemCanvas.DrawPointCircleFilled(60, 43, 2, Color::RGB(101, 67, 33));
        itemCanvas.DrawPointCircleFilled(53, 60, 3, Color::RGB(101, 67, 33));
        itemCanvas.DrawPointCircleFilled(43, 57, 2, Color::RGB(101, 67, 33));
        itemCanvas.DrawPointCircleFilled(58, 54, 2, Color::RGB(101, 67, 33));

        // Okraj cookie
        itemCanvas.DrawPointCircle(50, 50, 20, Color::RGB(160, 130, 90));
    }
};



#endif //SWORD_HPP
