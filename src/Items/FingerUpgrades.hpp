//
// Created by Lukáš Kaplánek on 20.11.2025.
//
#ifndef FINGERUPGRADES_HPP
#define FINGERUPGRADES_HPP
#include "Item.hpp"

class ReinforcedFinger:public Item{
public:
    ReinforcedFinger():Item("Second",100,0.0,1.0,1) {
        setDisplayName("Second");
    };
};

class Ambidextrous:public Item{
public:
    Ambidextrous():Item("Hardened",500,0.0,2.0,2) {
        setDisplayName("Hardened");
    };
};

class ThousandFingers:public Item{
public:
    ThousandFingers():Item("Thousand",10000,0.0,5.0,3) {
        setDisplayName("Thousand");
    };
};

class MillionFingers:public Item{
public:
    MillionFingers():Item("Million",100000,0.0,10.0,4) {
        setDisplayName("Million");
    };
};

class BillionFingers:public Item{
public:
    BillionFingers():Item("Billion",1000000,0.0,50.0,5) {
        setDisplayName("Billion");
    };
};



#endif //FINGERUPGRADES_HPP