//
// Created by root on 11/18/25.
//

#include "../Items/Sword.hpp"
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>

using namespace ftxui;

int main(int argc, char *argv[]) {
    auto sword = Sword();

    auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
    auto itemTest = vbox(
        text("Vítej v ultimátním cookie clickeru!") | center | bold | color(Color::Blue) ,
        separator() ,
        canvas(sword.itemCanvas) | center
    ) | border;



    Render(screen, itemTest);
    screen.Print();
    return 0;
}
