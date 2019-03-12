/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** CPool_Day04_2018
*/

void my_swapchar(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}