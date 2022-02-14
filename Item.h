/**
 * Project 9: Dragon Adventure, RPG game
 * @file Item.h
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */
#ifndef ITEM_H
#define ITEM_H
#include <ncurses.h>
#include <string>
#include <iostream>

using namespace std;

class Party;

class Item {
public:
    Item(int price, string name);
    Item();
    int price() const;
    void set_effect();
    int get_effect() const;
    virtual char get_type() = 0;
    virtual void observe(WINDOW * game_window, int y_max, int x_max) = 0;
    virtual void buy(WINDOW * game_window, Party & party, int y_max, int x_max) = 0;

protected:
    int _price;
    string _name;
    int _effect;
};

#endif // ITEM_H
