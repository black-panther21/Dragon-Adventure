/**
 * Project 9: Dragon Adventure, RPG game
 * @file main.cpp
 * @author Black Panther, Cyber Penguin
 * @collaborators N/A
 * @date Dec. 10, 2021
 */

 #include "Item.h"
 #include <ncurses.h>
 #include "Hero.h"
 #include "Villain.h"
 #include "Party.h"
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <algorithm>
 #include <memory>

#define NUM_A_ITEMS 8
#define NUM_D_ITEMS 7
#define NUM_CHARS 9
#define ITEM_TYPES 2

const vector<Hero *> HEROES = {new Hero("Warrior", 125, 100, 10, 1),
                               new Hero("Gladiator", 150, 50, 20, 1),
                               new Hero("Fairy", 100, 200, 10, 1),
                               new Hero("Wizard", 100, 300, 10, 1),
                               new Hero("Alchemist", 100, 250, 10, 1),
                               new Hero("Shield-Bearer", 100, 70, 10, 1),
                               new Hero("Tank", 300, 50, 60, 1),
                               new Hero("Elf", 100, 175, 5, 1),
                               new Hero("Thief", 70, 100, 10, 1)};

const vector<Villain> VILLAINS = {Villain("Goblin", 50, 5, 10),
                                  Villain("Dragon", 40, 7, 10),
                                  Villain("Orc", 60, 8, 10),
                                  Villain("Thug", 30, 10, 10),
                                  Villain("Vampire", 40, 4, 10),
                                  Villain("Dwarf", 55, 5, 10),
                                  Villain("Dark Elf", 45, 6, 10),
                                  Villain("Zombie", 50, 7, 10),
                                  Villain("Worewolf", 55, 8, 10)};

const vector<AttackItem *> A_ITEMS = {new AttackItem(49, "Doran's Blade"),
                                      new AttackItem(48, "Infinity Edge"),
                                      new AttackItem(48, "Guinsoo's Rageblade"),
                                      new AttackItem(49, "B.F. Sword"),
                                      new AttackItem(48, "Rapid Firecannon"),
                                      new AttackItem(47, "Overcharged"),
                                      new AttackItem(5, "Rabadon's Deathcap"),
                                      new AttackItem(12, "Glacial Buckler")};

const vector<DefenseItem *> D_ITEMS = {new DefenseItem(1, "Timeworn Targon's Brace"),
                                       new DefenseItem(10, "Spirit Visage"),
                                       new DefenseItem(7, "Sunfire Cape"),
                                       new DefenseItem(19, "Cloth Armor"),
                                       new DefenseItem(30, "Chain Vest"),
                                       new DefenseItem(5, "Health Potion"),
                                       new DefenseItem(8, "Mercury's Treads Boots")};

using namespace std;

/**
* Get a random index for an attack item
* @return rand() % NUM_A_ITEMS a number between 0 and 7
*/
int random_attack_item() {
    srand (time(0));
    return rand() % NUM_A_ITEMS;
}

/**
* Get a random index for a defense item
* @return rand() % NUM_D_ITEMS a number between 0 and 6
*/
int random_defense_item() {
    srand (time(0));
    return rand() % NUM_D_ITEMS;
}

/**
* Get a random index for an attack item
* @return rand() % ITEM_TYPES a number between 0 and 1
*/
int random_item_type() {
    srand (time(0));
    return rand() % ITEM_TYPES;
}

/**
* Get a random index for an attack item
* @return rand() % NUM_A_ITEMS a number between 0 and 8
*/
int random_character() {
    srand (time(0));
    return rand() % NUM_CHARS;
}

/**
* setup ncurses paramters and color pairs
*/
void setup_ncurses() {
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}

/**
* Print the word DRAGON
* @param y_value the specific y value to start printing at
* @param x_value the specific x value to start printing at
*/
void print_dragon(int y_value, int x_value) {
    mvprintw(y_value + 1, x_value,
            " ______   ______    _______  _______  _______  __    _  ");
    mvprintw(y_value + 2, x_value,
            "|      | |    _ |  |   _   ||       ||       ||  |  | |");
    mvprintw(y_value + 3, x_value,
            "|  _    ||   | ||  |  |_|  ||    ___||   _   ||   |_| |");
    mvprintw(y_value + 4, x_value,
            "| | |   ||   |_||_ |       ||   | __ |  | |  ||       |");
    mvprintw(y_value + 5, x_value,
            "| |_|   ||    __  ||       ||   ||  ||  |_|  ||  _    |");
    mvprintw(y_value + 6, x_value,
            "|       ||   |  | ||   _   ||   |_| ||       || | |   |");
    mvprintw(y_value + 7, x_value,
            "|______| |___|  |_||__| |__||_______||_______||_|  |__| ");
}

/**
* Print the word ADVENTURE
* @param y_value the specific y value to start printing at
* @param x_value the specific x value to start printing at
*/
void print_adventure(int y_value, int x_value) {
    mvprintw(y_value + 8, x_value,
            " _______  ______   __   __  _______  __    _  _______  __   __  ______    _______");
    mvprintw(y_value + 9, x_value,
            "|   _   ||      | |  | |  ||       ||  |  | ||       ||  | |  ||    _ |  |       |");
    mvprintw(y_value + 10, x_value,
            "|  |_|  ||  _    ||  |_|  ||    ___||   |_| ||_     _||  | |  ||   | ||  |    ___|");
    mvprintw(y_value + 11, x_value,
            "|       || | |   ||       |"
            "|   |___ |       |  |   |  |  |_|  ||   |_||_ |   |___ ");
    mvprintw(y_value + 12, x_value,
            "|       || |_|   ||       ||    ___||  _    |"
            "  |   |  |       ||    __  ||    ___|");
    mvprintw(y_value + 13, x_value,
            "|   _   ||       | |     | |   |___ | | |   "
            "|  |   |  |       ||   |  | ||   |___ ");
    mvprintw(y_value + 14, x_value,
            "|__| |__||______|   |___|  |_______||_|  |__|  "
            "|___|  |_______||___|  |_||_______|");
}

/**
* Print the TITLE
* @param ymax the maximum y value possible
* @param xmax the maximum x value possible
*/
void show_title(int ymax, int xmax) {
    int y_value = ymax / 5;
    int x_value = xmax / 3;
    print_dragon(y_value, x_value);
    print_adventure(y_value, x_value);
    refresh();
}

/**
 * Create a user friendly menu
 * @param choices[] array of choices
 * @param choice user's choice
 * @param highlight choice to be highlighted on screen
 * @param menu_win Ncurses window
 * @param width width of window
 */
void menu(string choices[], int & choice, int & highlight,
                            WINDOW * menu_win, int width) {
    while (1) {
        for (int index = 0; index < 3; index++) {
            if (index == highlight)
                wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, index + 1, (width / 2) - 1,
                      choices[index].c_str());
            wattroff(menu_win, A_REVERSE);
        }
        choice = wgetch(menu_win);
        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 3)
                    highlight = 2;
                break;
            default:
                break;
        }
        if (choice == 10)
            break;
    }

}

/**
 * Display the home menu
 * @param ymax maximum y
 * @param xmax maximum x
 * @param height height of window
 * @param width width of window
 * @return highlight the chosen item
 */
int home_menu(int ymax, int xmax, int height, int width) {
    WINDOW * menu_win = newwin(height, width, (ymax - height) / 2, (xmax - width) / 2);
    wattron(menu_win, COLOR_PAIR(1));
    refresh();
    wrefresh(menu_win);
    keypad(menu_win, true);

    string choices[3] = {"Play", "Help", "Quit"};
    int choice = 0;
    int highlight = 0;

    menu(choices, choice, highlight, menu_win, width);

    wattroff(menu_win, COLOR_PAIR(1));
    return highlight;
}

/**
* A function that establishes a frame for the fight window
* @param fight_window the window associated with fight
*/
void fight_window_frame(WINDOW * fight_window) {
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = int('|');
    top = bottom = int('_');
    tlc = trc = blc = brc = int('x');

    wborder(fight_window, left, right, top, bottom, tlc, trc, blc, brc);
}

/**
* A function that establishes a frame for the main game window
* @param character_status the window associated with characters
* @param fight_window the window associated with fight
*/
void main_game_frame(WINDOW * character_status, WINDOW * game_window) {
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = int('|');
    top = bottom = int('_');
    tlc = trc = blc = brc = int('x');

    wborder(character_status, left, right, top, bottom, tlc, trc, blc, brc);
    wborder(game_window, left, right, top, bottom, tlc, trc, blc, brc);

    wrefresh(character_status);
    wrefresh(game_window);
}

/**
* display the opening scene
* @param fight_window the window associated with fight
*/
void opening_scene(WINDOW * game_window) {
    mvwprintw(game_window, 3, 5,
              "Dear Adventurer, welcome to Dragon Adventures");
    mvwprintw(game_window, 4, 5,
              "Your Journey starts here. At first, you will be alone.");
    mvwprintw(game_window, 5, 5,
              "Along the way, you will meet amazing friends and formidable foes.");
    mvwprintw(game_window, 6, 5,
              "Put together a great party and enjoy yourself :)");
    mvwprintw(game_window, 10, 5,
              "[Press Enter to continue]");

    wrefresh(game_window);
    getch();
    wclear(game_window);
    wrefresh(game_window);
}

/**
 * A helper function that prints current hp
 * @param character_status character stat window
 * @param party main game party
 * @param start_x starting x value
 * @param party_index index of current party member
 */
void print_hp(WINDOW * character_status, Party & party, int start_x, size_t party_index) {
    string temp_str;
    temp_str = to_string (party.get_hero(party_index)->hp());
    mvwprintw(character_status, 3, start_x, "HP: ");
    if (party.get_hero(party_index)->hp() <= 0) {
        mvwprintw(character_status, 3, start_x + 4, "0");
    } else {
    mvwprintw(character_status, 3, start_x + 4, temp_str.c_str());
    mvwprintw(character_status, 3, start_x + 7, " / ");
    temp_str = to_string (party.get_hero(party_index)->max_hp());
    mvwprintw(character_status, 3, start_x + 10, temp_str.c_str());
    }
}

/**
 * A helper function that prints current mp
 * @param character_status character stat window
 * @param party main game party
 * @param start_x starting x value
 * @param party_index index of current party member
 */
void print_mp(WINDOW * character_status, Party & party,
              int start_x, size_t party_index) {
    int difference = party.get_hero(party_index)->mp() -
        party.get_hero(party_index)->max_mp();
    string temp_str;
    if (difference >= 0)
        party.get_hero(party_index)->lower_mp(difference);
    temp_str = to_string (party.get_hero(party_index)->mp());
    mvwprintw(character_status, 4, start_x, "MP: ");
    mvwprintw(character_status, 4, start_x + 4, temp_str.c_str());
    mvwprintw(character_status, 4, start_x + 7, " / ");
    temp_str = to_string (party.get_hero(party_index)->max_mp());
    mvwprintw(character_status, 4, start_x + 10, temp_str.c_str());
}

/**
 * A helper function that prints current xp and level
 * @param character_status character stat window
 * @param party main game party
 * @param start_x starting x value
 * @param party_index index of current party member
 */
void print_experience(WINDOW * character_status, Party & party,
                      int start_x, size_t party_index) {
    string temp_str;
    temp_str = to_string (party.get_hero(party_index)->xp());
    mvwprintw(character_status, 5, start_x, "XP: ");
    mvwprintw(character_status, 5, start_x + 4, temp_str.c_str());
    mvwprintw(character_status, 5, start_x + 7, " / 100");

    temp_str = to_string (party.get_hero(party_index)->level());
    mvwprintw(character_status, 6, start_x, "LVL: ");
    mvwprintw(character_status, 6, start_x + 4, temp_str.c_str());
}

/**
 * A helper function that prints current attack & defense effects
 * @param character_status character stat window
 * @param party main game party
 * @param start_x starting x value
 * @param party_index index of current party member
 */
void print_abilities(WINDOW * character_status, Party & party,
                     int start_x, size_t party_index) {
    string temp_str;
    mvwprintw(character_status, 7, start_x, "Attack: ");
    temp_str = to_string (party.get_hero(party_index)->attack());
    mvwprintw(character_status, 7, start_x + 8, temp_str.c_str());

    mvwprintw(character_status, 8, start_x, "Defense: ");
    temp_str = to_string (party.get_hero(party_index)->defense());
    mvwprintw(character_status, 8, start_x + 9, temp_str.c_str());
}

/**
 * A helper function that prints current coins
 * @param character_status character stat window
 * @param party main game party
 */
void print_coins(WINDOW * character_status, Party & party) {
    string temp_str;
    mvwprintw(character_status, 10, 1, "Party Coins: ");
    temp_str = to_string (party.coins());
    mvwprintw(character_status, 10, 14, temp_str.c_str());
}

/**
 * A function that prints current status of party members
 * @param character_status character stat window
 * @param party main game party
 */
void update_stats(WINDOW * character_status, Party & party) {
    int start_x = 1;
    string temp_str;
    wclear(character_status);

    for (size_t party_index = 0; party_index < party.total_members(); party_index++) {
        mvwprintw(character_status, 2, start_x,
                  party.get_hero(party_index)->get_name().c_str());
        print_hp(character_status, party, start_x, party_index);
        print_mp(character_status, party, start_x, party_index);
        print_experience(character_status, party, start_x, party_index);
        print_abilities(character_status, party, start_x, party_index);

        start_x += 45;
    }
    print_coins(character_status, party);
    wrefresh(character_status);
}

/**
 * A function that moves party on the map
 * @param party main game party
 * @param game_window main gameplay window
 */
void move_party(Party & party, WINDOW * game_window) {
    party.show();
    int y_max, x_max;
    getmaxyx(game_window, y_max, x_max);
    mvwprintw(game_window, y_max - 1, x_max - 65,
            "[Explore the area as much as you want! Press A to start figting!]");
    wrefresh(game_window);

    while (party.get_move() != 'a'){
        party.show();
        wrefresh(game_window);
    }

}

/**
 * A helper function that prints stats during fight prints vectory message
 * in case of winning
 * @param fight_window fight window
 * @param y_max maximum y value possible
 * @param x_max maximum x value possible
 * @param enemy a random enemy object
 * @param won reference to boolean for whether the fight is won or not
 */
void update_fight_stat(WINDOW * fight_window, int y_max,
                       int x_max, Villain enemy, bool & won) {
        string temp_str = to_string(enemy.hp());
        mvwprintw(fight_window, y_max / 8 + 3, x_max / 8 + 41, "HP: ");
        if (enemy.hp() <= 0) {
            mvwprintw(fight_window, y_max / 8 + 3, x_max / 8 + 45,"00");
            mvwprintw(fight_window, y_max / 8 + 4, x_max / 8 + 25,"YOU WON!");
            won = true;
            enemy.is_dead(fight_window,y_max, x_max);
        } else {
            mvwprintw(fight_window, y_max / 8 + 3, x_max / 8 + 45,"  ");
            mvwprintw(fight_window, y_max / 8 + 3, x_max / 8 + 45, temp_str.c_str());
        }
        wrefresh(fight_window);
}

/**
 * A helper function that makes sure we are adding a unique hero
 * @param champions a reference to the main party
 * @param won boolean for whether the fight is won or not
 * @param lost boolean for whether the fight is lost or not
 * @return true if hero is unique and false otherwise
 */
 bool unique(Hero * unique, Party & champions) {
     return champions.is_unique(unique);
 }

/**
 * A function that updates stats during fight for the main hero object
 * @param champions a reference to the main party
 * @param won boolean for whether the fight is won or not
 * @param lost boolean for whether the fight is lost or not
 */
void refresh_stats(Party & champions, bool won, bool lost) {
    int mp_difference = champions.get_leader()->max_mp() - champions.get_leader()->mp();
    int hp_difference = champions.get_leader()->max_hp() - champions.get_leader()->hp();
    if (won) {
        if (mp_difference > 0 && mp_difference < champions.get_leader()->max_mp())
            champions.get_leader()->raise_mp(mp_difference);
        if (hp_difference > 0 && hp_difference < champions.get_leader()->max_hp())
            champions.get_leader()->lower_hp(-hp_difference);
        champions.get_leader()->level_up();
        if (champions.get_leader()->level() % 2 == 0 &&
            champions.get_leader()->level() <= 6 &&
            champions.get_leader()->xp() == 0) {
            Hero * unique_hero = HEROES[random_character()];
            while (!unique(unique_hero, champions)) {
                unique_hero = HEROES[random_character()];
            }
            champions.add_hero(unique_hero);
        }
        champions.add_coins(100);
    }
    if (lost) {
        champions.remove_leader();
    }
}

/**
 * A helper function that sets up the fight window
 * @param y_max max y value
 * @param x_max max x value
 * @param enemy current villain
 */
WINDOW * set_up_fight_window(int y_max, int x_max, Villain enemy) {
    WINDOW * fight_window = newwin(y_max / 2, x_max / 2, y_max / 4, x_max / 4);
    wattron(fight_window, A_REVERSE);
    wattron(fight_window, COLOR_PAIR(2));
    fight_window_frame(fight_window);

    mvwprintw(fight_window, y_max / 8, x_max / 8, enemy.get_name().c_str());
    mvwprintw(fight_window, y_max / 8 + 1, x_max / 8, "Has appeared! FIGHT!");
    wrefresh(fight_window);

    mvwprintw(fight_window, y_max / 8 + 2, x_max / 8, "[PRESS S TO ATTACK]");
    mvwprintw(fight_window, y_max / 8 + 3, x_max / 8, "[PRESS D TO DEFEND]");
    wrefresh(fight_window);

    return fight_window;
}

/**
 * A helper function that concludes the fight & indicate the result
 * @param fight_window the fight window
 * @param champions a reference to the main party
 * @param keep_playing a reference to bool for staying in game or not
 * @param won reference to boolean for whether the fight is won or not
 * @param lost reference to boolean for whether the fight is lost or not
 */
void conclude_fight(WINDOW * fight_window, Party & champions,
                    bool & keep_playing, bool & won, bool & lost) {
    getch();
    wattroff(fight_window, A_REVERSE);
    wattroff(fight_window, COLOR_PAIR(2));
    werase(fight_window);
    wrefresh(fight_window);

    refresh_stats(champions, won, lost);
    if (champions.total_members() == 0) {
        keep_playing = false;
    }
}

/**
 * A function that cotrols the fights
 * @param character_status the character stats window
 * @param y_max max y value
 * @param x_max max x value
 * @param enemy current villain
 * @param champions a reference to the main party
 * @param keep_playing a reference to bool for staying in game or not
 */
void fight(WINDOW * character_status, int y_max, int x_max,
           Villain enemy, Party & champions, bool & keep_playing) {
    WINDOW * fight_window = set_up_fight_window(y_max, x_max, enemy);
    bool won = false;
    bool lost = false;
    update_fight_stat(fight_window, y_max, x_max, enemy, won);
    char fight_choice = getch();

    while ((fight_choice == 's' || fight_choice == 'd') && !won && !lost) {
        if (!won && !lost) {
            if (fight_choice == 's') {
                if (champions.get_leader()->mp() >= 5) {
                    enemy.lower_hp(champions.get_leader()->attack());
                    champions.get_leader()->lower_mp(5);
                    update_fight_stat(fight_window, y_max, x_max, enemy, won);
                }
            }
            else if (fight_choice == 'd') {
                champions.get_leader()->lower_hp(enemy.attack());
                champions.get_leader()->raise_mp(10);
            }
        }
        update_stats(character_status, champions);
        if (champions.get_leader()->hp() <= 0) {
            champions.get_leader()->is_dead(fight_window, y_max, x_max);
            lost = true;
            fight_choice = '\0';
        }
        else
            fight_choice = getch();
    }
    conclude_fight(fight_window, champions, keep_playing, won, lost);
}

/**
 * A function that checks wheather the user ultimatelly lost or not
 * @param game_window the game main window
 * @param y_max max y value
 * @param x_max max x value
 * @param keep_playing a reference to bool for staying in game or not
 * @return keep_playing wheather we should keep playing or not
 */
bool continue_playing(WINDOW * game_window, int y_max, int x_max, bool & keep_playing) {
    mvwprintw(game_window, y_max / 2 - 5, x_max / 2 - 20,
              "[PRESS X TO STOP PLAYING OR B TO CONTINUE]");
    wrefresh(game_window);
    getch();
    char key = getch();
    if (key == 'x') {
        keep_playing = false;
        return keep_playing;
    }
    wmove(game_window, y_max / 2 - 5, x_max / 2 - 20);
    wclrtoeol(game_window);
    return keep_playing;
}

/**
 * A helper function to handle attack item system
 * @param game_window game window
 * @param champions game party
 * @param y_max max y value
 * @param x_max max x value
 */
void handle_attack(WINDOW * game_window, Party & champions, int y_max, int x_max) {
    AttackItem * weapon = A_ITEMS[random_attack_item()];
    weapon->observe(game_window, y_max, x_max);
    char decision = getch();
    if (decision == 'b' && champions.coins() >= weapon->price()) {
        weapon->buy(game_window, champions, y_max, x_max);
        champions.get_leader()->equip_weapon(weapon);
    } else {
        weapon->clear_item(game_window, y_max, x_max);
    }
}

/**
 * A helper function to handle defense item system
 * @param game_window game window
 * @param champions game party
 * @param y_max max y value
 * @param x_max max x value
 */
void handle_defense(WINDOW * game_window, Party & champions, int y_max, int x_max) {
    DefenseItem * armor = D_ITEMS[random_defense_item()];
    armor->observe(game_window, y_max, x_max);
    char decision = getch();
    if (decision == 'b' && champions.coins() >= armor->price()) {
        armor->buy(game_window, champions, y_max, x_max);
        champions.get_leader()->equip_armor(armor);
    } else {
        armor->clear_item(game_window, y_max, x_max);
    }
}

/**
 * A function to handle item system
 * @param game_window game window
 * @param champions game party
 * @param y_max max y value
 * @param x_max max x value
 */
void items(WINDOW * game_window, Party & champions, int y_max, int x_max) {
    Party lfguhflgkjh = champions;
    int type = random_item_type();

    if (type == 0) {
        handle_attack(game_window, champions, y_max, x_max);
    }
    if (type == 1) {
        handle_defense(game_window, champions, y_max, x_max);
    }
}

/**
 * A funtion to handle main game phases
 * @param y_max max y value
 * @param x_max max x value
 */
void main_game(int y_max, int x_max) {
    int height = y_max / 5;
    WINDOW * character_status = newwin(height, x_max, y_max - height, 0);
    WINDOW * game_window = newwin(y_max - height, x_max, 0, 0);
    wattron(character_status, COLOR_PAIR(1));
    wattron(game_window, COLOR_PAIR(1));
    keypad(game_window, true);

    main_game_frame(character_status, game_window);

    Hero * main_hero = HEROES[random_character()];
    Party champions = Party(main_hero, game_window);
    bool keep_playing = true;
    opening_scene(game_window);

    while (keep_playing) {
        update_stats(character_status, champions);
        move_party(champions, game_window);
        Villain enemy = VILLAINS[random_character()];
        wclear(game_window);
        wrefresh(game_window);
        fight(character_status, y_max, x_max, enemy, champions, keep_playing);
        if (keep_playing) {
            if (continue_playing(game_window, y_max, x_max, keep_playing)) {
                items(game_window, champions, y_max, x_max);
            }
        }
    }
    clear();
    wattroff(character_status, COLOR_PAIR(1));
    wattroff(game_window, COLOR_PAIR(1));
}

/**
 * A helper function to handle help menu text
 * @param help_menu
 */
void help_text(WINDOW * help_menu) {
    mvwprintw(help_menu, 4, 1, "Dragon Adventure is  game in which the player controls a character");
    mvwprintw(help_menu, 5, 1, "(champion) with a set of unique charactrestics. Over the course of");
    mvwprintw(help_menu, 6, 1, "an adventure, champions gain levels by accruing experience points (XP)");
    mvwprintw(help_menu, 7, 1, "through killing enemies. Items also increase champions' strength, and");
    mvwprintw(help_menu, 8, 1, "are bought with coins, which players accrue passively over time and");
    mvwprintw(help_menu, 9, 1, "earn actively by defeating enemies. You will start the game with empty");
    mvwprintw(help_menu, 10, 1, "map with P representing your location. You have the chance to move");
    mvwprintw(help_menu, 11, 1, "around as you want! Whenever you feel like fighting a villain, just");
    mvwprintw(help_menu, 12, 1, "press 'A' and some bad guy will appear! Be careful, you will find a");
    mvwprintw(help_menu, 13, 1, "lot of them! While fighting, you will have the chance to either attack");
    mvwprintw(help_menu, 14, 1, "or defend. By attacking you are certainly lowering the enemy's hp, but");
    mvwprintw(help_menu, 15, 1, "you are also losing your mp. Make sure not to hit 0 mp as you won't be");
    mvwprintw(help_menu, 16, 1, "able to attack anymore, and you may get killed! We don't want that. By");
    mvwprintw(help_menu, 17, 1, "defending, you can save your mp, and also have time to restore it and");
    mvwprintw(help_menu, 18, 1, "lower the damage you take from the enemy. So, pay attantion to this");
    mvwprintw(help_menu, 19, 1, "tradeoff between defending and attacking!");

    mvwprintw(help_menu, 23, 1, "Throughout the game, you will meet new people who will join your party");
    mvwprintw(help_menu, 24, 1, "and you will be able to use coins together to buy items that");
    mvwprintw(help_menu, 25, 1, "will help you during fights either by increasing your attack");
    mvwprintw(help_menu, 26, 1, "damage or defense power. In case of death, ouch, one of your");
    mvwprintw(help_menu, 27, 1, "fellow party members will take over the fight. You can technically");
    mvwprintw(help_menu, 28, 1, "continue playing as long as you have one party member at least.");
    mvwprintw(help_menu, 29, 1, "If all of them die, it's GAME OVER!");

    mvwprintw(help_menu, 33, 1, "The main purpose of the game is earning more and more xp and coins");
    mvwprintw(help_menu, 34, 1, "as well as leveling up! You can simply compete with other people");
    mvwprintw(help_menu, 35, 1, "on how much further you could go. In an RPG text-based game like");
    mvwprintw(help_menu, 36, 1, "ours, we expect you to use your imagination to fullest. You will ");
    mvwprintw(help_menu, 37, 1, "also need to think about when to attack and when to defend to survive");
    mvwprintw(help_menu, 38, 1, "fierce battles as we described above. Finally, we would liek to remind");
    mvwprintw(help_menu, 39, 1, "you to relax and have fun!");

}

/**
 * A helper function to handle dragon head
 * @param help_menu
 * @param x_max max x value
 */
void help_dragon_head(WINDOW * help_menu, int x_max) {
    mvwprintw(help_menu, 3, x_max / 2 - 20, "111111111111111111111111111¶¶¶¶111111111111111111111");
    mvwprintw(help_menu, 4, x_max / 2 - 20, "1111111111111111111111111¶¶¶¶11111111111111111111111");
    mvwprintw(help_menu, 5, x_max / 2 - 20, "11111111111111111111111¶¶¶¶¶¶11111111111111111111111");
    mvwprintw(help_menu, 6, x_max / 2 - 20, "111111111111111111111¶¶¶¶¶¶1111¶¶¶11¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1");
    mvwprintw(help_menu, 7, x_max / 2 - 20, "111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111111");
    mvwprintw(help_menu, 8, x_max / 2 - 20, "11111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111111111");
    mvwprintw(help_menu, 9, x_max / 2 - 20, "11111111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11");
    mvwprintw(help_menu, 10, x_max / 2 - 20, "1111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111111");
    mvwprintw(help_menu, 11, x_max / 2 - 20, "111111111111¶¶¶111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111");
    mvwprintw(help_menu, 12, x_max / 2 - 20, "111111111¶¶¶¶¶11¶¶¶¶¶¶¶¶¶¶¶11¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111");
    mvwprintw(help_menu, 13, x_max / 2 - 20, "11111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1¶¶1111¶¶¶¶¶¶¶¶¶¶¶¶¶11¶¶¶¶¶11");
    mvwprintw(help_menu, 14, x_max / 2 - 20, "1111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111¶11111¶¶¶¶¶¶¶¶¶¶¶¶¶111¶¶¶¶1");
    mvwprintw(help_menu, 15, x_max / 2 - 20, "11¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111¶¶¶");
    mvwprintw(help_menu, 16, x_max / 2 - 20, "1¶¶¶¶¶¶¶¶111111111111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111¶");
    mvwprintw(help_menu, 17, x_max / 2 - 20, "11¶¶¶¶¶111111111111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111");
    mvwprintw(help_menu, 18, x_max / 2 - 20, "1111¶1111111111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111");
    mvwprintw(help_menu, 19, x_max / 2 - 20, "1111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111");
    mvwprintw(help_menu, 20, x_max / 2 - 20, "111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11¶¶¶¶¶11111");
    mvwprintw(help_menu, 21, x_max / 2 - 20, "11111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111¶¶¶¶¶11111");
    mvwprintw(help_menu, 22, x_max / 2 - 20, "11111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111¶¶¶¶11111");
    mvwprintw(help_menu, 23, x_max / 2 - 20, "111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111111¶¶¶¶11111");
    mvwprintw(help_menu, 24, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111¶¶¶¶¶¶111111111111111¶¶¶111111");
}

/**
 * A helper function to handle dragon tail
 * @param help_menu
 * @param x_max max x value
 */
void help_dragon_tail(WINDOW * help_menu, int x_max) {
    mvwprintw(help_menu, 25, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111111111111111111111111111¶¶1111111");
    mvwprintw(help_menu, 26, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶¶1111111111111111111¶¶111111111111111111");
    mvwprintw(help_menu, 27, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶111111111111111111111¶¶¶¶111111111111111");
    mvwprintw(help_menu, 28, x_max / 2 - 20, "¶¶¶¶¶¶¶1¶¶¶111111111111111111111111¶¶¶¶¶111111111111");
    mvwprintw(help_menu, 29, x_max / 2 - 20, "¶¶¶¶¶¶¶11¶¶11111111111111111¶¶1111111¶¶¶¶¶¶¶11111111");
    mvwprintw(help_menu, 30, x_max / 2 - 20, "¶¶¶¶¶¶¶¶111¶11111111111111111¶¶¶1111111¶¶¶¶¶¶1111111");
    mvwprintw(help_menu, 31, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶¶11111111111111111¶¶¶¶111111¶¶¶¶¶¶111111");
    mvwprintw(help_menu, 32, x_max / 2 - 20, "¶¶¶¶¶¶¶¶111¶111111111111¶¶¶11111¶¶¶¶111¶¶¶¶¶¶¶111111");
    mvwprintw(help_menu, 33, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶11111111111111111¶¶¶11111¶¶¶¶¶¶¶¶¶¶¶¶¶¶1111");
    mvwprintw(help_menu, 34, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶11111111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11");
    mvwprintw(help_menu, 35, x_max / 2 - 20, "¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶");
    mvwprintw(help_menu, 36, x_max / 2 - 20, "1¶¶¶¶¶¶¶¶¶¶¶¶111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111¶¶¶¶¶¶¶¶¶¶¶");
    mvwprintw(help_menu, 37, x_max / 2 - 20, "1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111111111¶¶¶¶¶¶");
    mvwprintw(help_menu, 38, x_max / 2 - 20, "1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111111111111¶¶¶¶");
    mvwprintw(help_menu, 39, x_max / 2 - 20, "1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111111111¶¶¶¶¶¶");
    mvwprintw(help_menu, 40, x_max / 2 - 20, "11¶¶¶¶1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11¶¶¶¶¶¶¶¶11111111111111¶¶¶");
    mvwprintw(help_menu, 41, x_max / 2 - 20, "11¶¶¶11111¶¶¶¶¶¶¶¶¶¶¶¶¶11111¶¶¶¶¶¶¶¶¶¶11111111111111");
    mvwprintw(help_menu, 42, x_max / 2 - 20, "1¶¶¶11111111¶¶¶1¶¶¶¶¶¶¶¶¶11111¶¶¶¶¶11111111111111111");
    mvwprintw(help_menu, 43, x_max / 2 - 20, "1¶¶¶111111111111111¶¶¶¶¶¶¶1111111¶¶¶¶¶¶¶¶11111111111");
    mvwprintw(help_menu, 44, x_max / 2 - 20, "11¶¶1111111111111111111¶¶¶¶¶111111111111111111111111");
    mvwprintw(help_menu, 45, x_max / 2 - 20, "111¶11111111111111111111¶¶¶¶111111111111111111111111");
    mvwprintw(help_menu, 46, x_max / 2 - 20, "1111111111111111111111111¶¶¶111111111111111111111111");
    mvwprintw(help_menu, 47, x_max / 2 - 20, "11111111111111111111111111¶¶111111111111111111111111");
}

/**
 * A function to handle help menu
 * @param y_max max y value
 * @param x_max max x value
 * @return exit_char char to indicate exiting the help window
 */
char help_menu(int y_max, int x_max) {
    WINDOW * help_menu = newwin(y_max, x_max, 0, 0);
    wattron(help_menu, COLOR_PAIR(1));

    mvwprintw(help_menu, 1, x_max / 3 + 25, "Welcome to Dragon Adventure!");
    mvwprintw(help_menu, y_max - 1, x_max - 40,
             "[PRESS ANY KEY TO GO BACK TO MAIN MENU!]");
    help_text(help_menu);
    help_dragon_head(help_menu, x_max);
    help_dragon_tail(help_menu, x_max);

    wrefresh(help_menu);
    char exit_char = getch();
    wclear(help_menu);
    wrefresh(help_menu);
    return exit_char;
}

/**
 * runs the game
 * @param y_max, max y value
 * @param x_max, max x value
 * @param height, height of screen
 * @param width, width of screen
 */
void run_game(int ymax, int xmax, int height, int width) {
    char switch_char = 'a';
    while (switch_char != 'x') {
        show_title(ymax, xmax);
        int action = home_menu(ymax, xmax, height, width);
        if (action == 0)
            main_game(ymax, xmax);
        else if (action == 1)
            switch_char = help_menu(ymax, xmax);
        else
            switch_char = 'x';
    }
}

/**
 * A function that clears the memory allocated for the data base
 */
void clear_memory() {
    for_each(HEROES.begin(), HEROES.end(), default_delete<Hero>());
    for_each(A_ITEMS.begin(), A_ITEMS.end(), default_delete<AttackItem>());
    for_each(D_ITEMS.begin(), D_ITEMS.end(), default_delete<DefenseItem>());
}

// Controls operation of program
int main() {
    setup_ncurses();
    int ymax = 0;
    int xmax = 0;
    getmaxyx(stdscr, ymax, xmax);
    int height = ymax / 10;
    int width = xmax / 10;

    run_game(ymax, xmax, height, width);

    attroff(COLOR_PAIR(1));
    refresh();
    endwin();
    clear_memory();
    return 0;
}
