/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** PSU_my_sokoban_2018
*/

#include "sokoban.h"

void display_map(char **map, data_t *data)
{
    for (int i = 0; i < data->lines; i++)
        for (int j = 0; data->map[i][j] != '\0'; j++)
            data->map[i][j] = (data->original[i][j] == 'O' &&
                data->map[i][j] == ' ') ? 'O' : data->map[i][j];
    for (int i = 0; map[i]; i++)
        mvprintw((LINES/2) - (data->lines/2) + i, (COLS/2) -
            (my_strlen(map[i])/2), map[i]);
}

int check_stuck(data_t *data, int i, int j)
{
    int count = 0;

    count += (data->map[i - 1][j] == '#') ? 1 : 0;
    count += (data->map[i + 1][j] == '#') ? 1 : 0;
    count += (data->map[i][j - 1] == '#') ? 3 : 0;
    count += (data->map[i][j + 1] == '#') ? 3 : 0;
    if (count >= 4 && count != 6)
        return (84);
    return (0);
}

void check_end_game(data_t *data)
{
    int count = 0;

    for (int i = 0; i < data->lines; i++)
        for (int j = 0; data->map[i][j] != '\0'; j++)
            count += (data->original[i][j] == 'O'
                && data->map[i][j] == 'X') ? 1 : 0;
    if (count == data->storage)
        data->end = 0;
    count = 0;
    for (int i = 0; i < data->lines; i++)
        for (int j = 0; data->map[i][j] != '\0'; j++)
            count += (data->map[i][j] == 'X' && data->original[i][j] != 'O'
                && check_stuck(data, i, j) == 84) ? 1 : 0;
    if (count == data->box)
        data->end = 1;
}

void analyse_event(data_t *data)
{
    switch (getch()) {
    case 65:
        move_up(data);
        break;
    case 66:
        move_down(data);
        break;
    case 67:
        move_right(data);
        break;
    case 68:
        move_left(data);
        break;
    case 32:
        init_sokoban(data);
        break;
    }
}

int game_loop(data_t *data)
{
    initscr();
    attron(A_NORMAL);
    while (1) {
        clear();
        display_map(data->map, data);
        analyse_event(data);
        check_end_game(data);
        if (data->end != 42) {
            display_map(data->map, data);
            refresh();
            endwin();
            return (data->end);
        }
        refresh();
    }
}