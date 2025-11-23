//
// Created by Lukáš Kaplánek on 18.11.2025.
//

#include "Item.hpp"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include "../stb_image.h"

void Item::drawFromPNG(const std::string& filename) {
    int width, height, channels;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &channels, 4);

    if (!data) return;
    for (int y = 0; y < height && y < 16; y++) {
        for (int x = 0; x < width && x < 16; x++) {
            int index = (y * width + x) * 4;

            unsigned char a = data[index + 3];

            if (a > 128) {
                this->itemCanvas.DrawPoint(x, y, true, Color::RGB(data[index], data[index + 1], data[index + 2]));
            }
        }
    }
    stbi_image_free(data);
}

Item::Item(const std::string& name, int baseCost, double cps, double clickPower, int requiredLevel):name(name),baseCost(baseCost), cps(cps), clickPower(clickPower), requiredLevel(requiredLevel)
{
    selected = new bool(false);
    drawFromPNG("assets/"+name+".png");
    displayName = name;
    description = "No description available.";
}


void Item::setDisplayName(const std::string& name) {
    displayName = name;
};
void Item::setDescription(const std::string& desc) {
    description = desc;
}