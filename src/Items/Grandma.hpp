#ifndef GRANDMA_HPP
#define GRANDMA_HPP
#include "Item.hpp"


class Grandma : public Item {
public:
    Grandma():Item("grandma", 500, 5.0, 0.0, 2) {
        setDisplayName("Grandma");
    }
};



#endif //GRANDMA_HPP
