/**
 * Project 9: Dragon Adventure, RPG game
 * @file Party.h
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 11, 2021
 */
#ifndef PARTY_H
#define PARTY_H

#include <ncurses.h>
#include "Hero.h"
#include <string>
#include <vector>

using namespace std;

class Party {
public:
    Party(Hero * hero, WINDOW * game_window);
    void add_hero(Hero * hero);
    void add_coins(int coins);
    void spend_coins(int price);
    void change_leader(Hero * hero);
    void remove_leader();
    int coins() const;
    int level() const;
    bool is_empty() const;
    bool is_unique(Hero * unique) const;
    size_t total_members() const;
    Hero * get_leader() const;
    Hero * get_hero(size_t index) const;
    void move_up();
    void move_down();
    void move_right();
    void move_left();
    int get_move();
    void show();

protected:
    int _coins;
    size_t _total_members;
    vector<Hero *> _hero_vector;
    int _x_loc;
    int _y_loc;
    int _y_max;
    int _x_max;
    WINDOW * _game_window;
};

#endif // party_H
