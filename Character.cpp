/**
 * Project 9: Dragon Adventure, RPG game
 * @file Character.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */
#include "Character.h"

/**
 * Character constructor based on name and hp
 * @param name the name of the item
 * @param hp the hp of the character
 */
Character::Character(string name, int hp) {
    _name = name;
    _hp = hp;
}

/**
 * A default Character constructor
 */
Character::Character() {}

/**
 * A method to lower the hp of a designated character
 * @param amount the amound the hp should be lowered by
 */
void Character::lower_hp(int amount) {
    _hp = _hp - amount;
}

/**
 * A method to get the current hp
 * @return _hp the current hp of a character
 */
int Character::hp() const {
    return _hp;
}

/**
 * A method to get the current level
 * @return _level the current level of a character
 */
int Character::level() const {
    return _level;
}

/**
 * A method to get the current hp
 * @return _hp the current hp of a character
 */
string Character::get_name() const {
    return _name;
}
