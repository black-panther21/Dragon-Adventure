/**
 * Project 9: Dragon Adventure, RPG game
 * @file Hero.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */

#include "Hero.h"

#define XP_NEEDED 100

Hero::Hero(string name, int hp, int mp, int damage, int level) {
    _name = name;
    _xp = 0;
    _damage = damage;
    _defense = 0;
    _level = level;
    _hp = hp;
    _mp = mp;
    _max_hp = hp;
    _max_mp = mp;
    _dead = false;
    _armor = nullptr;
    _weapon = nullptr;
}

Hero::Hero() {
}

/**
 * equip weapon to leader
 * @param weapon, weapon item
 */
void Hero::equip_weapon(AttackItem * weapon) {
    _weapon = weapon;
}

/**
 * equip armor to leader
 * @param armor, armor item
 */
void Hero::equip_armor(DefenseItem * armor) {
    _armor = armor;
}

/**
 * update XP stats
 */
void Hero::level_up() {
    _xp += 50;
    if (_xp >= XP_NEEDED) {
        _level += 1;
        _xp -= XP_NEEDED;
    }
}

/**
 * checks if the leader is dead in a fight
 * @param fight_window, main fight window
 * @param y_max, max y value
 * @param x_max, max x value
 */
void Hero::is_dead(WINDOW * fight_window, int y_max, int x_max) {
    if (_hp <= 0) {
        _dead = true;
    }
    mvwprintw(fight_window, y_max / 8 + 5, x_max / 8 + 25,"YOU LOST!");
    wrefresh(fight_window);
}

/**
 * get mp
 * @return _mp, current mp
 */
int Hero::mp() const {
    return _mp;
}

/**
 * get max hp
 * @return _max_hp, current max  hp
 */
int Hero::max_hp() const {
    return _max_hp;
}

/**
 * get max mp
 * @return _max_mp, current max  mp
 */
int Hero::max_mp() const {
    return _max_mp;
}

/**
 * get xp
 * @return _xp, current xp
 */
int Hero::xp() const {
    return _xp;
}

/**
 * get Leader's attack stat
 * @return _damage, can be boosted by weapon effect
 */
int Hero::attack() {
    if(_weapon != nullptr)
        return _damage + _weapon->get_effect();
    else
        return _damage;
}

/**
 * get Leader's defense stat
 * @return _damage, equal to armor effect
 */
int Hero::defense() const {
    if(_armor != nullptr)
        return _armor->get_effect();
    return 0;
}

/**
 * lower mp value by amount
 * @param amount, amount to be lowered by
 */
void Hero::lower_mp(int amount) {
    _mp = _mp - amount;
}

/**
 * raise mp value by amount
 * @param amount, amount to be raised by
 */
void Hero::raise_mp(int amount) {
    _mp = _mp + amount;
}
