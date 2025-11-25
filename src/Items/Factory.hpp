#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "Item.hpp"


class Factory : public Item{
public:
    Factory():Item("Factory", 1200, 8.0, 0.0, 10) {};
    setDisplayName("Cookie Factory");
};



#endif //FACTORY_HPP
