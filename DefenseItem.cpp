/**
 * Project 9: Dragon Adventure, RPG game
 * @file DefenseItem.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 11, 2021
 */
#include "DefenseItem.h"
#include "Party.h"

/**
 * Defense Item constructor based on price and name
 * @param price the price of the item
 * @param name the name of the item
 */
DefenseItem::DefenseItem(int price, string name) {
    set_effect();
    _price = price;
    _name = name;
}

/**
 * Defense Item default constructor that sets _effect to 0
 */
DefenseItem::DefenseItem() {
    _effect = 0;
}

/**
 * A method that gets the item type
 * @return 'a' to indicate that this is an defense item
 */
char DefenseItem::get_type() {
    return 'a';
}

/**
 * A method to print the random stats and user's possible decisions
 * @param game_window the window to print at
 * @param y_max the maximum height of the window
 * @param x_max the maximum width of the window
 */
void DefenseItem::observe(WINDOW * game_window, int y_max, int x_max) {
    mvwprintw(game_window, y_max / 2, x_max / 2, "Defence Items Shop is here! You can buy a new Item if you want!");
    mvwprintw(game_window, y_max / 2 + 1, x_max / 2, _name.c_str());

    string temp_str = to_string (get_effect());
    mvwprintw(game_window, y_max / 2 + 2, x_max / 2, "Defense: ");
    mvwprintw(game_window, y_max / 2 + 2, x_max / 2 + 9, temp_str.c_str());

    temp_str = to_string (price());
    mvwprintw(game_window, y_max / 2 + 3, x_max / 2, "Price: ");
    mvwprintw(game_window, y_max / 2 + 3, x_max / 2 + 9, temp_str.c_str());

    mvwprintw(game_window, y_max / 2 + 5, x_max / 2, "[PRESS B TO BUY OR X TO IGNORE]");
    wrefresh(game_window);
}

/**
 * A method that clears the observed item's text
 * @param game_window the window to print at
 * @param y_max the maximum height of the window
 * @param x_max the maximum width of the window
 */
void DefenseItem::clear_item(WINDOW * game_window, int y_max, int x_max) {
    wmove(game_window, y_max / 2, x_max / 2);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2 + 1, x_max / 2);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2 + 2, x_max / 2);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2 + 2, x_max / 2 + 9);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2 + 4, x_max / 2);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2 + 3, x_max / 2);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2 + 5, x_max / 2);
    wclrtoeol(game_window);
    wrefresh(game_window);
}

/**
 * A method to buy the random item, deduct the price from coins, and clear the window
 * @param game_window the window to print at
 * @param party champions party that hold heroes
 * @param y_max the maximum height of the window
 * @param x_max the maximum width of the window
 */
void DefenseItem::buy(WINDOW * game_window, Party & party, int y_max, int x_max) {
    clear_item(game_window, y_max, x_max);
    if (party.coins() >= _price)
        mvwprintw(game_window, y_max / 2 - 1, x_max / 2, "You Just Bought ");
    else
        mvwprintw(game_window, y_max / 2 - 1, x_max / 2,
                 "You Don't have Enough Coins ");
    mvwprintw(game_window, y_max / 2 - 1, x_max / 2 + 16, _name.c_str());
    mvwprintw(game_window, y_max / 2, x_max / 2, "[PRESS ANY KEY TO KEEP GOING!]");
    wrefresh(game_window);

    if (party.coins() >= _price) {
        party.spend_coins(_price);
    }

    getch();
    wmove(game_window, y_max / 2 - 1, x_max / 2);
    wclrtoeol(game_window);
    wmove(game_window, y_max / 2, x_max / 2);
    wclrtoeol(game_window);
    wrefresh(game_window);
}
