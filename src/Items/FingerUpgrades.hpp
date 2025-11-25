//
// Created by Lukáš Kaplánek on 20.11.2025.
//
#ifndef FINGERUPGRADES_HPP
#define FINGERUPGRADES_HPP
#include "Item.hpp"

class ReinforcedFinger:public Item{
public:
    ReinforcedFinger():Item("Cursor",100,0.0,1.0,1) {
        setDisplayName("Reinforced Finger");
    };
};

class Ambidextrous:public Item{
public:
    Ambidextrous():Item("Cursor",500,0.0,2.0,2) {
        setDisplayName("Ambidextrous");
    };
};

class ThousandFingers:public Item{
public:
    ThousandFingers():Item("Cursor",10000,0.0,5.0,3) {
        setDisplayName("Thousand Fingers");
    };
};

class MillionFingers:public Item{
public:
    MillionFingers():Item("Cursor",100000,0.0,10.0,4) {
        setDisplayName("Million Fingers");
    };
};

class BillionFingers:public Item{
public:
    BillionFingers():Item("Cursor",1000000,0.0,50.0,5) {
        setDisplayName("Billion Fingers");
    };
};



#endif //FINGERUPGRADES_HPP