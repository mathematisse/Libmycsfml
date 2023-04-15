/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Main function for my_paint
*/

#include <stdlib.h>
#include "panel/panel.h"

int is_concerned(ptype_t t)
{
    if (t == PTYPE_DDBUTT ||
        t == PTYPE_EVBUTT ||
        t == PANEL_TYPE_INPUT)
        return 1;
    return 0;
}

int fast_atoi(const char *str)
{
    int val = 0;
    while (*str) {
        val = val * 10 + *str - '0';
        str++;
    }
    return val;
}

void save_as_png(sfTexture* texture, const char* path)
{
    sfImage *image = sfTexture_copyToImage(texture);
    if (!sfImage_saveToFile(image, path)) {
        sfImage_destroy(image);
        return;
    }
    sfImage_destroy(image);
    return;
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
