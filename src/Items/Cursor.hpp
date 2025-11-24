//
// Created by Lukáš Kaplánek on 20.11.2025.
//

#ifndef CURSOR_HPP
#define CURSOR_HPP
#include "Item.hpp"


class Cursor : public Item{
public:
    Cursor(): Item("Cursor", 15, 0.1, 0.0) {
        setDisplayName("Test");
    }
};



#endif //CURSOR_HPP
