/**
 * Project 9: Dragon Adventure, RPG game
 * @file Villain.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */

#include "Villain.h"

/**
 * Villain Constructor based on name, hp, damage, and coins
 * @param name the name of the item
 * @param hp the villain's hp
 * @param damage the villain's chosen damage
 * @param coins the villain's chosen coins to be added after winning
 */
Villain::Villain (string name, int hp, int damage, int coins) {
    _name = name;
    _hp = hp;
    _damage = damage;
    _coins = coins;
    _dead = false;
}

/**
 * An attack method that gets the gets the villain's damage
 * @return _damage the villain's chosen damage
 */
int Villain::attack() {
    return _damage;
}

/**
 * A method to check if villain is alive and change the private variable _dead
 * as well as printing a winning message
 */
void Villain::is_dead(WINDOW * fight_window, int y_max, int x_max) {
    if (_hp <= 0) {
        _dead = true;
    }

    mvwprintw(fight_window, y_max / 8 + 5, x_max / 8 + 25,"YOU WON!");
}
