//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#ifndef SWORD_HPP
#define SWORD_HPP
#include "../Item.hpp"


class Sword : public Item{

    Sword(): Item("Sword", 100, 0, 0) {

       itemCanvas.DrawPointCircleFilled(50, 30, 6, Color::RGB(200, 200, 210));   // horní část čepele
itemCanvas.DrawPointCircleFilled(50, 40, 7, Color::RGB(190, 190, 200));
itemCanvas.DrawPointCircleFilled(50, 50, 8, Color::RGB(180, 180, 190));   // střed čepele
itemCanvas.DrawPointCircleFilled(50, 60, 7, Color::RGB(190, 190, 200));
itemCanvas.DrawPointCircleFilled(50, 70, 6, Color::RGB(200, 200, 210));   // spodní část (u záštity)

// Zvýraznění hrany čepele
itemCanvas.DrawPointCircle(50, 30, 6, Color::RGB(160, 160, 170));
itemCanvas.DrawPointCircle(50, 50, 8, Color::RGB(160, 160, 170));
itemCanvas.DrawPointCircle(50, 70, 6, Color::RGB(160, 160, 170));


// Záštita meče
itemCanvas.DrawPointCircleFilled(40, 75, 5, Color::RGB(150, 120, 60));
itemCanvas.DrawPointCircleFilled(60, 75, 5, Color::RGB(150, 120, 60));
itemCanvas.DrawPointCircleFilled(50, 75, 8, Color::RGB(170, 140, 80));     // střed záštity

// Okraje záštity
itemCanvas.DrawPointCircle(40, 75, 5, Color::RGB(120, 90, 40));
itemCanvas.DrawPointCircle(60, 75, 5, Color::RGB(120, 90, 40));


// Rukojeť meče
itemCanvas.DrawPointCircleFilled(50, 85, 6, Color::RGB(90, 60, 30));
itemCanvas.DrawPointCircleFilled(50, 95, 6, Color::RGB(90, 60, 30));

// Textura rukojeti (vzorek)
itemCanvas.DrawPointCircleFilled(46, 85, 2, Color::RGB(60, 40, 20));
itemCanvas.DrawPointCircleFilled(54, 95, 2, Color::RGB(60, 40, 20));

// Spodní zakončení rukojeti (hlavička)
itemCanvas.DrawPointCircleFilled(50, 105, 5, Color::RGB(120, 80, 40));
itemCanvas.DrawPointCircle(50, 105, 5, Color::RGB(90, 60, 30));
    }
};



#endif //SWORD_HPP
