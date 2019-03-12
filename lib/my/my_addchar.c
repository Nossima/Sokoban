/*
** EPITECH PROJECT, 2018
** my_addchar.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include "my.h"

char *my_addchar(char *str, char c)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));

    for (i; str[i] != '\0'; i++)
        result[i] = str[i];
    result[i] = c;
    i++;
    result[i] = '\0';
    str = my_strdup(result);
    free(result);
    return (str);
}