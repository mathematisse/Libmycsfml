/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Factory foos for canvases
*/

#include "stdlib.h"
#include "canvas.h"

canvas_t *canvas_create(panel_t **panels)
{
    canvas_t *canvas = NULL;

    if (!panels || !panels[0])
        return NULL;
    canvas = malloc(sizeof(canvas_t));
    if (!canvas)
        return NULL;
    canvas->panels = panels;
    canvas->hovered = NULL;
    canvas->pressed = NULL;
    canvas->selected = NULL;
    return canvas;
}

void canvas_destroy(canvas_t *canvas)
{
    for (int i = 0; canvas->panels[i]; i++)
        panel_destroy(canvas->panels[i]);
    free(canvas);
}
