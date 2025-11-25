#ifndef GRANDMA_HPP
#define GRANDMA_HPP
#include "Item.hpp"


class Grandma : public Item {
public:
    grandma():Item("grandma", 500, 5.0, 0.0, 5) {};
    setDisplayName("Baking grandma");
};



#endif //GRANDMA_HPP
