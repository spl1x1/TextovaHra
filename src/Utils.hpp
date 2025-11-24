//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <ftxui/dom/canvas.hpp>

using namespace ftxui;
class Utils {
public:
    static void drawFromPNG(const std::string& filename, Canvas *canvas);

};



#endif //UTILS_HPP
