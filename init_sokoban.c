/*
** EPITECH PROJECT, 2018
** init_sokoban.c
** File description:
** PSU_my_sokoban_2018
*/

#include "sokoban.h"

int init_sokoban(data_t *data)
{
    data->player[0] = -1;
    data->player[1] = -1;
    for (int i = 0; i <= data->lines; i++)
        data->map[i] = my_strdup(data->original[i]);
    for (int i = 0; i <= data->lines; i++)
        for (int j = 0; data->original[i][j] != '\0'; j++) {
            data->player[0] = (data->original[i][j] == 'P') ? i :
                data->player[0];
            data->player[1] = (data->original[i][j] == 'P') ? j :
                data->player[1];
        }
    if (data->player[0] == -1)
        return (84);
    return (0);
}

int check_map(data_t *data)
{
    int count = 0;

    for (int i = 0; i < data->lines; i++)
        for (int j = 0; data->original[i][j] != '\0'; j++)
            count += (data->original[i][j] != 'O'
                && data->original[i][j] != '#' && data->original[i][j] != ' '
                && data->original[i][j] != 'X' && data->original[i][j] != 'P'
                && data->original[i][j] != '\n')
                ? 1 : 0;
    if (count != 0)
        return (84);
    return (0);
}

int init_base(data_t *data)
{
    if (check_map(data) == 84)
        return (84);
    data->storage = 0;
    data->box = 0;
    data->end = 42;
    for (int i = 0; i < data->lines; i++)
        for (int j = 0; data->original[i][j] != '\0'; j++)
            data->storage += (data->original[i][j] == 'O') ? 1 : 0;
    for (int i = 0; i < data->lines; i++)
        for (int j = 0; data->original[i][j] != '\0'; j++)
            data->box += (data->original[i][j] == 'X') ? 1 : 0;
    if (data->storage != data->box)
        return (84);
    return (0);
}