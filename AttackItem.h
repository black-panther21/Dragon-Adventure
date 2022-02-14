/**
 * Project 9: Dragon Adventure, RPG game
 * @file AttackItem.h
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 11, 2021
 */
#ifndef ATTACKITEM_H
#define ATTACKITEM_H
#include "Item.h"

class AttackItem : public Item {
public:
    AttackItem(int price, string name);
    AttackItem();
    char get_type();
    void clear_item(WINDOW * game_window, int y_max, int x_max);
    void observe(WINDOW * game_window, int y_max, int x_max);
    void buy(WINDOW * game_window, Party & party, int y_max, int x_max);
};

#endif // ATTACKITEM_H
