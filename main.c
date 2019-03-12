/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** PSU_my_sokoban_2018
*/

#include "sokoban.h"

int get_map_size(data_t *data, char *path)
{
    FILE *fd = fopen(path, "r");
    size_t len = 0;
    char *temp = NULL;
    struct stat buf;

    data->lines = 0;
    data->columns = 0;
    if (stat(path, &buf) == -1)
        return (84);
    if ((buf.st_mode & S_IFREG) == 0)
        return (84);
    data->columns = (int)getline(&temp, &len, fd);
    for (; getline(&temp, &len, fd) > 0; data->lines++);
    data->original= malloc(sizeof(char *) * (data->lines + 2));
    data->map = malloc(sizeof(char *) * (data->lines + 2));
    for (int i = 0; i <= data->lines; i++)
        data->map[i] = malloc(sizeof(char) * (data->columns + 1));
    fclose(fd);
    return (0);
}

int read_map(data_t *data, char *path)
{
    FILE *fd;
    size_t len = 0;
    ssize_t size;

    if (get_map_size(data, path) == 84)
        return (84);
    fd = fopen(path, "r");
    if (fd == NULL)
        return (84);
    for (int i = 0; i < (data->lines + 2); i++)
        data->original[i] = NULL;
    size = getline(&(data->original[0]), &len, fd);
    for (int i = 1; size > 0; i++) {
        data->columns = (size > data->columns) ? (int)size : data->columns;
        size = getline(data->original + i, &len, fd);
    }
    fclose(fd);
    return (0);
}

void print_help(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap\tfile "
        "representing the warehouse map, containing '#' for walls, 'P' for the"
        "player, 'X' for boxes and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));

    data->lines = 0;
    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        print_help();
    else {
        if (read_map(data, av[1]) == 84)
            return (84);
        if (init_base(data) == 84 || init_sokoban(data) == 84)
            return (84);
    }
    return (game_loop(data));
}