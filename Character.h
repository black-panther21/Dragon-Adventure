/**
 * Project 9: Dragon Adventure, RPG game
 * @file Character.h
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */
#ifndef CHARACTER_H
#define CHARACTER_H
#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

class Character {
public:
    Character(string name, int hp);
    Character();
    void lower_hp(int amount);
    int hp() const;
    int level() const;
    string get_name() const;
    virtual int attack() = 0;
    virtual void is_dead(WINDOW * fight_window, int y_max, int x_max) = 0;

protected:
    string _name;
    int _hp;
    int _mp;
    int _level;
};


#endif // CHARACTER_H
