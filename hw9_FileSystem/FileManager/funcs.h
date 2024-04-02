#ifndef FUNCS_H
#define FUNCS_H

#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

extern volatile sig_atomic_t signal_status;

void sighandler(int s);
void init();
void finish();
void print_left_border(struct winsize size, int mid, WINDOW **border_left_win);
void print_right_border(struct winsize size, int mid, WINDOW **border_right_win);
void print_left_win(struct winsize size, int mid, WINDOW **border_left_win, WINDOW **left_win);
void print_right_win(struct winsize size, int mid, WINDOW **border_right_win, WINDOW **right_win);
int min(int a, int b);
void print_files_list(WINDOW *win, struct dirent **file_list, int n, int curr_row, int up_bnd, int low_bnd);

#endif
