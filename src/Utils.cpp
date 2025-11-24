//
// Created by Lukáš Kaplánek on 23.11.2025.
//

#include "Utils.hpp"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

void Utils::drawFromPNG(const std::string& filename, Canvas *canvas) {
    int width, height, channels;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &channels, 4);

    if (!data) return;
    for (int y = 0; y < height && y < 16; y++) {
        for (int x = 0; x < width && x < 16; x++) {
            int index = (y * width + x) * 4;

            unsigned char a = data[index + 3];

            if (a > 128) {
                canvas->DrawPoint(x, y, true, Color::RGB(data[index], data[index + 1], data[index + 2]));
            }
        }
    }
    stbi_image_free(data);
}
