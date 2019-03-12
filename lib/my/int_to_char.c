/*
** EPITECH PROJECT, 2018
** int _to_char.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>

char *int_to_char(int nb)
{
    char *str;
    int len = 0;
    int number = nb;
    int final;

    for (len; number > 0; len++)
        number /= 10;
    str = malloc(sizeof(char) * (len + 1));
    final = len;
    number = len - 1;
    for (len; len > 0; len--) {
        str[number] = (nb % 10 + 48);
        nb /= 10;
        number--;
    }
    str[final] = '\0';
    return (str);
}

char *long_to_char(long int nb)
{
    char *str;
    int len = 0;
    int number = nb;
    int final;

    for (len; number > 0; len++)
        number /= 10;
    str = malloc(sizeof(char) * (len + 1));
    final = len;
    number = len - 1;
    for (len; len > 0; len--) {
        str[number] = (nb % 10 + 48);
        nb /= 10;
        number--;
    }
    str[final] = '\0';
    return (str);
}