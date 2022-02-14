#ifndef FIGHT_H
#define FIGHT_H

#include "Hero.h"
#include "Villain.h"

class Fight {
public:
    Fight(Hero hero, Villain villain);
    void result(Hero hero, Villain villain);
    void attack();
    void defend();
    void change_turn();
protected:
    bool _won;
    int _turn;
    Hero _hero;
    Villain _villain;
};

#endif // fight_H
