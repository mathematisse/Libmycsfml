/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for cursor object
*/

#ifndef CURSOR_H
    #define CURSOR_H
    #include <SFML/Graphics.h>

typedef struct cursor_s {
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
} cursor_t;

cursor_t *cursor_create(void);
void cursor_destroy(cursor_t *cursor);
void cursor_set_pos(cursor_t *cursor, sfVector2f pos);

#endif /* CURSOR_H */
