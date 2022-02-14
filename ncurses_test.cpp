#include <ncurses.h>

int main() {
    initscr();

    if (!has_colors()) {   
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    attron(COLOR_PAIR(1));

    addstr("Hello World!");
    attroff(COLOR_PAIR(1));
    refresh();
    getch();

    endwin();
    return 0;
}
