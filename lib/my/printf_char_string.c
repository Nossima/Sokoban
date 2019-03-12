/*
** EPITECH PROJECT, 2018
** printf_char_string.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include "my.h"

char *handle_unprint(char *str)
{
    char *result = malloc_str(1);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < ' ' || str[i] > '~')
            result = my_strcat(result,
                my_strcat(my_strdup("\\"), dec_to_octal(str[i])));
        else
            result = my_addchar(result, str[i]);
    }
    return (result);
}

char *get_string_unprint(char *str, va_list print)
{
    return (my_strcat(str, handle_unprint(va_arg(print, char *))));
}

char *get_string(char *str, va_list print)
{
    return (my_strcat(str, va_arg(print, char *)));
}

char *get_char(char *str, va_list print)
{
    return (my_addchar(str, va_arg(print, int)));
}

char *add_percent(char *str, va_list print)
{
    return (my_strcat(str, "%"));
}