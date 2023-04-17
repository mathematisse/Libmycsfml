/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for button panels
*/

#ifndef DRAGGABLE_H
    #define DRAGGABLE_H
    #include "panel.h"

typedef struct panel_drag_s {
    sfVector2f initpos;
    sfVector2f offset;
    sfFloatRect bounds;
} panel_drag_t;

panel_t *make_drag(sfVector2f pos);

panel_drag_t *drag_create(void);
panel_t *panel_item_drag_create(rectransform_t *rect, ptype_t type);
void panel_drag_destroy(panel_t *panel);

#endif /* DRAGGABLE_H */