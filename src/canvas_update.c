/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** extra functions for the csfml program
*/

#include "canvas.h"

void canvas_draw(sfRenderWindow *window, canvas_t *canvas)
{
    if (!window || !canvas)
        return;
    for (int i = 0; canvas->panels[i]; i++)
        panel_draw(window, canvas->panels[i]);
}
