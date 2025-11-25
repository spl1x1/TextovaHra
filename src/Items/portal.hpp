#ifndef PORTAL_HPP
#define PORTAL_HPP
#include "Item.hpp"

class portal:public Item{
public:
    portal():Item("portal",5000,20.0,0.0,20) {
        setDisplayName("Cookieverse Portal");
    }
};

#endif //PORTAL_HPP