#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "Item.hpp"


class Factory : public Item {
public:
    Factory():Item("Factory", 3000, 15.0, 0.0, 10) {
        setDisplayName("Factory");
    }
};



#endif //FACTORY_HPP
