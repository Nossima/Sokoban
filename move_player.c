/*
** EPITECH PROJECT, 2018
** move_player.c
** File description:
** PSU_my_sokoban_2018
*/

#include "sokoban.h"

void move_up(data_t *data)
{
    if (data->map[data->player[0] - 1][data->player[1]] == 'X')
        move_box(data, data->player[0], data->player[1], 1);
    if (data->map[data->player[0] - 1][data->player[1]] == ' '
        || data->map[data->player[0] - 1][data->player[1]] == 'O') {
        data->map[data->player[0]][data->player[1]] = ' ';
        data->map[data->player[0] - 1][data->player[1]] = 'P';
        data->player[0]--;
    }
}

void move_down(data_t *data)
{
    if (data->map[data->player[0] + 1][data->player[1]] == 'X')
        move_box(data, (data->player[0]), (data->player[1]), 2);
    if (data->map[data->player[0] + 1][data->player[1]] == ' '
        || data->map[data->player[0] + 1][data->player[1]] == 'O') {
        data->map[data->player[0]][data->player[1]] = ' ';
        data->map[data->player[0] + 1][data->player[1]] = 'P';
        data->player[0]++;
    }
}

void move_right(data_t *data)
{
    if (data->map[data->player[0]][data->player[1] + 1] == 'X')
        move_box(data, (data->player[0]), (data->player[1]), 3);
    if (data->map[data->player[0]][data->player[1] + 1] == ' '
        || (data->map[data->player[0]][data->player[1] + 1] == 'O')) {
        data->map[data->player[0]][data->player[1]] = ' ';
        data->map[data->player[0]][data->player[1] + 1] = 'P';
        data->player[1]++;
    }
}

void move_left(data_t *data)
{
    if (data->map[data->player[0]][data->player[1] - 1] == 'X')
        move_box(data, data->player[0], data->player[1], 4);
    if (data->map[data->player[0]][data->player[1] - 1] == ' '
        || data->map[data->player[0]][data->player[1] - 1] == 'O') {
        data->map[data->player[0]][data->player[1]] = ' ';
        data->map[data->player[0]][data->player[1] - 1] = 'P';
        data->player[1]--;
    }
}