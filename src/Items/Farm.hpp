//
// Created by Lukáš Kaplánek on 25.11.2025.
//

#ifndef FARM_HPP
#define FARM_HPP
#include "Item.hpp"

class Farm:public Item {
    public:
    Farm():Item("Farm",1200,8.0,0.0,5) {
        setDisplayName("Farm");
    };
};


#endif //FARM_HPP
