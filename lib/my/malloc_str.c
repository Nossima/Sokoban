/*
** EPITECH PROJECT, 2018
** malloc_str.c
** File description:
** PSU_my_printf_2018
*/

#include "my.h"

char *malloc_str(int len)
{
    char *str = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
        str[i] = '\0';
    return (str);
}

char *realloc_str(char *str, int len)
{
    char *result = malloc(sizeof(char) * len);

    result = my_strcpy(result, str);
    free(str);
    return (result);
}