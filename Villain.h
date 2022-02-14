/**
 * Project 9: Dragon Adventure, RPG game
 * @file Villain.h
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */

#ifndef VILLAIN_H
#define VILLAIN_H

#include "Character.h"

class Villain : public Character {
public:
    Villain(string name, int hp, int damage, int coins);
    int attack();
    void is_dead(WINDOW * fight_window, int y_max, int x_max);
private:
    int _coins;
    bool _dead;
    int _damage;
};

#endif // Villain_H
