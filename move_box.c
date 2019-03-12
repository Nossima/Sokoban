/*
** EPITECH PROJECT, 2018
** move_box.c
** File description:
** PSU_my_sokoban_2018
*/

#include "sokoban.h"

void move_the_box(data_t *data, int *tempx, int *tempy)
{
    if (data->map[tempx[0]][tempy[0]] != '#'
        && data->map[tempx[0]][tempy[0]] != 'X') {
        data->map[tempx[0]][tempy[0]] = 'X';
        data->map[tempx[1]][tempy[1]] = ' ';
    }
}

void move_bot_left(int y, int *tempy, int dir)
{
    switch (dir) {
    case 3:
        tempy[0] = y + 2;
        tempy[1] = y + 1;
        break;
    case 4:
        tempy[0] = y - 2;
        tempy[1] = y - 1;
        break;
    }
}

void move_box(data_t *data, int x, int y, int dir)
{
    int tempx[2] = {x, x};
    int tempy[2] = {y, y};

    switch (dir) {
    case 1:
        tempx[0] = x - 2;
        tempx[1] = x - 1;
        break;
    case 2:
        tempx[0] = x + 2;
        tempx[1] = x + 1;
        break;
    default:
        move_bot_left(y, tempy, dir);
        break;
    }
    move_the_box(data, tempx, tempy);
}