/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** CPool_Day08_2018
*/

#ifndef CPOOL_DAY08_2018_MY_H
#define CPOOL_DAY08_2018_MY_H

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str);
int my_showstr(char const *str);
int check_sort(int *array, int size);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *mu_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void my_swapchar(char *a, char *b);
char *my_strdup(char const *src);
char *concat_params(int ac, char **av);
int my_show_word_array(char *const *tab);
char **alloc_dest(char **dest, char const *str);
char *clean_str(char *str);
char **my_str_to_word_array(char const *str);
char *convert_base(char const *nbr, char const *base_from,
    char const *base_to);
int is_alpha(char c);
int is_number(char c);
int my_sort_word_array(char **tab);
int my_advanced_sort_word_array(char **tab, int(*cmp)(char *const *,
    char const *));
char *int_to_char(int nb);
char *my_addchar(char *, char);
int my_printf(char *, ...);
int search_char(char *str, char c);

#endif //CPOOL_DAY08_2018_MY_H
