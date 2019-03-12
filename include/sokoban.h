/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** CPE_BSQ_2018
*/

#ifndef CPE_BSQ_2018_BSQ_H
#define CPE_BSQ_2018_BSQ_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

typedef struct data {
    char **original;
    char **map;
    int lines;
    int columns;
    int player[2];
    int storage;
    int box;
    int end;
} data_t;

int init_base(data_t *data);
int init_sokoban(data_t *data);
int game_loop(data_t *data);
void move_up(data_t *data);
void move_down(data_t *data);
void move_right(data_t *data);
void move_left(data_t *data);
void move_box(data_t *data, int x, int y, int dir);
void check_end_game(data_t *data);

#endif //CPE_BSQ_2018_BSQ_H
