/*
** EPITECH PROJECT, 2022
** Libmycsfml
** File description:
** Header for tools
*/

#ifndef TOOLS_H
    #define TOOLS_H

int is_interactable(ptype_t t);
int fast_atoi(const char *str);
char *str(const char *str, int i);
void init_text(sfText **text, sfFont *font, const char *str);
void init_rshape(sfRectangleShape **shape, sfColor color);
void init_sprite(sfSprite **sprite, sfTexture *texture, rectransform_t *r);
#endif /* TOOLS_H */
