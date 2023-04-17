/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Main function for my_paint
*/

#include <stdlib.h>

int fast_atoi(const char *str)
{
    int val = 0;
    while (*str) {
        val = val * 10 + *str - '0';
        str++;
    }
    return val;
}

char *str(const char *str, int i)
{
    char *new = malloc(sizeof(char) * (i + 1));
    int j = 0;

    while (j < i) {
        new[j] = str[j];
        j++;
    }
    new[j] = '\0';
    return new;
}
