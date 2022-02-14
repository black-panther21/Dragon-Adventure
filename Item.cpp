/**
 * Project 9: Dragon Adventure, RPG game
 * @file Item.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */
#include "Item.h"

/**
 * General Item constructor based on price and name
 * @param price the price of the item
 * @param name the name of the item
 */
Item::Item (int price, string name) {
    _price = price;
    _name = name;
    set_effect();
}

/**
 * A default Item constructor
 */
Item::Item() {}

/**
 * A method to get the price of an item
 * @return _price the price of a specifc item
 */
int Item::price() const {
    return _price;
}

/**
 * A method to set the effect of an item randomly
 */
void Item::set_effect() {
    srand(time(NULL));
    _effect = rand() % 10;
}

/**
 * A method to get the effect of a specific item
 */
int Item::get_effect() const {
    return _effect;
}
