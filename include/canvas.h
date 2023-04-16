/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for canvas struct
*/

#ifndef CANVAS_H
    #define CANVAS_H
    #include "panel/panel.h"

typedef struct canvas_s {
    panel_t **panels;
    panel_t *hovered;
    panel_t *pressed;
    panel_t *selected;
} canvas_t;

canvas_t *create_canvas(panel_t **panels);
void destroy_canvas(canvas_t *canvas);

#endif /* CANVAS_H */
