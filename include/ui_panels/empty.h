/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for empty panels
*/

#ifndef PANEL_EMPTY_H
    #define PANEL_EMPTY_H
    #include "panel.h"

typedef struct panel_empty_s {
    sfColor color;
} panel_empty_t;

panel_t *panel_empty_create(rectransform_t *rect, sfColor color);
void panel_empty_destroy(panel_t *panel);

#endif /* PANEL_EMPTY_H */
