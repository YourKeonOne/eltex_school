#include "funcs.h"

int main(void)
{
    init();

    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    int mid = size.ws_col / 2;
    
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    WINDOW *border_left_win;
    WINDOW *border_right_win;
    print_left_border(size, mid, &border_left_win);
    print_right_border(size, mid, &border_right_win);

    WINDOW *left_win;
    WINDOW *right_win;
    print_left_win(size, mid, &border_left_win, &left_win);
    print_right_win(size, mid, &border_right_win, &right_win);
    
    struct dirent **file_list_lw;
    int n_lw = 0;
    int curr_row_lw = 0;
    int up_bnd_lw = 0;
    int low_bnd_lw = size.ws_row - 2;
    char *curr_dir_lw = (char *)malloc(sizeof(char) * 2);
    strcpy(curr_dir_lw, ".");
    n_lw = scandir(curr_dir_lw, &file_list_lw, 0, alphasort);
    if(n_lw < 0)
    {
        finish();
        exit(-5);
    }
    else
    {
        print_files_list(left_win, file_list_lw, n_lw, curr_row_lw, up_bnd_lw, low_bnd_lw);
    }
    
    struct dirent **file_list_rw;
    int n_rw = 0;
    int curr_row_rw = 0;
    int up_bnd_rw = 0;
    int low_bnd_rw = size.ws_row - 2;
    char *curr_dir_rw = (char *)malloc(sizeof(char) * 2);
    strcpy(curr_dir_rw, ".");
    n_rw = scandir(curr_dir_rw, &file_list_rw, 0, alphasort);
    if(n_rw < 0)
    {
        finish();
        exit(-6);
    }
    else
    {
        print_files_list(right_win, file_list_rw, n_rw, curr_row_rw, up_bnd_rw, low_bnd_rw);
    }
    
    int curr_window = 1;
    char key = 0;

    while((key = wgetch(left_win)) != 'q')
    {
    
    }
    
    napms(3000);
    
    finish();
    return 0;
}
