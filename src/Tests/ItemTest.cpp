//
// Created by root on 11/18/25.
//

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>

#include "../Items/Cursor.hpp"

using namespace ftxui;

int main(int argc, char *argv[]) {
    auto item = Cursor();

    auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
    auto itemTest = vbox(
        text("Test ultimátního cookie clickeru!") | center | bold | color(Color::Blue) ,
        separator() ,
        canvas(item.itemCanvas) | center
    ) | border;



    Render(screen, itemTest);
    screen.Print();
    return 0;
}
