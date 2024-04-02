#include "funcs.h"

volatile sig_atomic_t signal_status = 0;

void sighandler(int s) {
    signal_status = s;
}

void init() {
    initscr();
    savetty();
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(BUTTON1_CLICKED, NULL);
    signal(SIGINT, sighandler);
    signal(SIGQUIT, sighandler);
    signal(SIGWINCH, sighandler);
    signal(SIGTSTP, sighandler);
}

void finish() {
    curs_set(1);
    clear();
    refresh();
    resetty();
    endwin();
}

void print_left_border(struct winsize size, int mid, WINDOW **border_left_win)
{
    *border_left_win = newwin(size.ws_row, mid, 0, 0);
    box(*border_left_win, '@', '@');
    if (*border_left_win == NULL)
    {
        finish();
        exit(-1);
    }
    wrefresh(*border_left_win);
}

void print_right_border(struct winsize size, int mid, WINDOW **border_right_win)
{
    *border_right_win = newwin(size.ws_row, mid, 0, mid);
    box(*border_right_win, '@', '@');
    if (*border_right_win == NULL)
    {
        finish();
        exit(-2);
    }
    wrefresh(*border_right_win);
}

void print_left_win(struct winsize size, int mid, WINDOW **border_left_win, WINDOW **left_win)
{
    *left_win = derwin(*border_left_win, size.ws_row - 2, mid - 2, 1, 1);
    if (*left_win == NULL)
    {
        finish();
        exit(-3);
    }
}

void print_right_win(struct winsize size, int mid, WINDOW **border_right_win, WINDOW **right_win)
{
    *right_win = derwin(*border_right_win, size.ws_row - 2, mid - 2, 1, 1);
    if (*right_win == NULL)
    {
        finish();
        exit(-4);
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void print_files_list(WINDOW *win, struct dirent **file_list, int n, int curr_row, int up_bnd, int low_bnd)
{
    werase(win);

    for(int i = up_bnd; i < min(n, low_bnd); i++)
    {
        wmove(win, i - up_bnd, 0);
        if(i == curr_row)
        {
            wattron(win, COLOR_PAIR(1));
            wprintw(win, "%s", file_list[i]->d_name);
            wattron(win, COLOR_PAIR(2));
        }
        else 
        {
            wprintw(win, "%s", file_list[i]->d_name);
        }
    }
    wrefresh(win);
}
