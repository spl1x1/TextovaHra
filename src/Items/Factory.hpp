//
// Created by Lukáš Kaplánek on 20.11.2025.
//

#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "Item.hpp"


class Factory : public Item{
public:
    Factory():Item("Factory", 1000, 8.0, 0.0, 2) {};
};



#endif //FACTORY_HPP
