/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <SFML/Graphics.h>

void init_text(sfText **text, sfFont *font, const char *str)
{
    sfFloatRect trect;

    if (!text || !font || !str)
        return;
    *text = sfText_create();
    if (!*text)
        return;
    sfText_setFont(*text, font);
    sfText_setString(*text, str);
    sfText_setCharacterSize(*text, 20);
    trect = sfText_getLocalBounds(*text);
    sfText_setOrigin(*text, (sfVector2f){trect.left + trect.width / 2.0f,
        trect.top + trect.height / 2.0f});
}
