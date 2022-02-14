/**
 * Project 9: Dragon Adventure, RPG game
 * @file Party.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 11, 2021
 */
#include "Party.h"

/**
 * Party Constructor based on the first hero and the game window
 * @param hero a pointer to the firsdt hero
 * @param game_window the main game window
 */
Party::Party(Hero * hero, WINDOW * game_window) {
    _total_members = 0;
    _coins = 0;
    _x_loc = 1;
    _y_loc = 1;
    getmaxyx(game_window, _y_max, _x_max);
    _game_window = game_window;
    add_hero(hero);
    change_leader(hero);
}

/**
 * A bool method to check if party is empty or not
 * @return the current number of party members
 */
bool Party::is_empty() const {
    return (_hero_vector.size() <= 0);
}

/**
 * A method that checks if hero is already in party or not
 * @param unique a pointer to hero to be added
 * @return true if hero is unique and false otherwise
 */
bool Party::is_unique (Hero * unique) const {
    for (size_t hero = 0; hero < _hero_vector.size(); hero++) {
        if (unique == _hero_vector[hero]) {
            return false;
        }
    }
    return true;
}

/**
 * A method to remove the current leader in case of death
 */
void Party::remove_leader() {
    _hero_vector.erase(_hero_vector.begin());
    _total_members--;
}

/**
 * A method to add a new hero to the party
 * @param hero a pointer to a random hero
 */
void Party::add_hero(Hero * hero) {
    _hero_vector.push_back(hero);
    _coins += 50;
    _total_members++;
}

/**
 * A method to change the hero of the party when the main hero dies
 * @param hero a pointer to a random hero
 */
void Party::change_leader(Hero * hero) {
    _hero_vector[0] = hero;
}

/**
 * A method to add coins to your party
 * @param coins number of coins to be added
 */
void Party::add_coins(int coins) {
    _coins += coins;
}

/**
 * A method to spend coins when buying something
 * @param price the price of item to be purchased
 */
void Party::spend_coins(int price) {
    _coins -= price;
}

/**
 * A method to get the current coins the party has
 * @return _coins the current coins the party has
 */
int Party::coins() const {
    return _coins;
}

/**
 * A method to get the current level the party leader has
 * @return the current level of the hero
 */
int Party::level() const {
    return _hero_vector[0]->level();
}

/**
 * A method to get the current total members of the party
 * @return _total_members the number of heroes in party
 */
size_t Party::total_members() const {
    return _total_members;
}

/**
 * A method to get the current leader of the party
 * @return the leader at index 0 of heroes vector
 */
Hero * Party::get_leader() const {
    return _hero_vector[0];
}

/**
 * A method to get the hero at a specific index
 * @param index the index to get the hero from
 * @return the hero at specific index of heroes vector
 */
Hero * Party::get_hero(size_t index) const {
    return _hero_vector[index];
}

/**
 * A method to print the party location on the screen
 */
void Party::show() {
    mvwprintw(_game_window, _y_loc, _x_loc, "P");
}

/**
 * A method to get the next movement from user
 * @return choice the user's movement choice
 */
int Party::get_move() {
    int choice = wgetch(_game_window);
    switch (choice) {
        case KEY_UP:
            move_up();
            break;
        case KEY_DOWN:
            move_down();
            break;
        case KEY_RIGHT:
            move_right();
            break;
        case KEY_LEFT:
            move_left();
            break;
    }
    return choice;
}

/**
 * A method to move the party up by 1
 */
void Party::move_up() {
    mvwprintw(_game_window, _y_loc, _x_loc, ".");
    _y_loc--;
    if (_y_loc < 1) {
        _y_loc = 1;
    }
}

/**
 * A method to move the party down by 1
 */
void Party::move_down() {
    mvwprintw(_game_window, _y_loc, _x_loc, ".");
    _y_loc++;
    if (_y_loc > _y_max - 2) {
        _y_loc = _y_max - 2;
    }
}

/**
 * A method to move the party left by 1
 */
void Party::move_left() {
    mvwprintw(_game_window, _y_loc, _x_loc, ".");
    _x_loc--;
    if (_x_loc < 1) {
        _x_loc = 1;
    }
}

/**
 * A method to move the party right by 1
 */
void Party::move_right() {
    mvwprintw(_game_window, _y_loc, _x_loc, ".");
    _x_loc++;
    if (_x_loc > _x_max - 2) {
        _x_loc = _x_max - 2;
    }
}
