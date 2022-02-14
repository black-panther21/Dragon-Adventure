/**
 * Project 9: Dragon Adventure, RPG game
 * @file Hero.h
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */

#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "AttackItem.h"
#include "DefenseItem.h"

class Hero : public Character {
public:
    Hero(string name, int hp, int mp, int damage, int level);
    Hero();
    void level_up();
    void is_dead(WINDOW * fight_window, int y_max, int x_max);
    int mp() const;
    int max_mp() const;
    int max_hp() const;
    int xp() const;
    int attack() ;
    int defense() const;
    void lower_mp(int amount);
    void raise_mp(int amount);
    void equip_weapon(AttackItem * weapon);
    void equip_armor(DefenseItem * armor);

private:
    int _max_hp;
    int _max_mp;
    int _xp;
    bool _dead;
    int _damage;
    int _defense;
    AttackItem * _weapon;
    DefenseItem * _armor;
};

#endif // HERO_H
