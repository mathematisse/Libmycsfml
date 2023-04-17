/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Event foos for canvases
*/

#include "canvas.h"
#include "panel.h"

void canvas_resize(canvas_t *c, sfVector2f *pos, sfVector2f *size)
{
    if (!c || !pos || !size)
        return;
    for (int i = 0; c->panels[i]; i++)
        panel_resize(c->panels[i], pos, size);
}

void canvas_hover(canvas_t *c, sfVector2i *pos)
{
    panel_t *hovered = NULL;

    if (!c)
        return;
    hovered = get_hovered_panel(c->panels, pos);
    if (hovered != c->hovered) {
        if (c->hovered != c->selected)
            on_panel_leave(c->hovered);
        if (hovered != c->selected)
            on_panel_enter(hovered);
        c->hovered = hovered;
    }
}

void canvas_pressed(canvas_t *c)
{
    c->pressed = c->hovered;
    if (c->pressed != c->selected)
        on_panel_pressed(c->pressed);
}

void canvas_released(canvas_t *c)
{
    if (c->pressed != c->selected)
        on_panel_released(c->pressed);
    if (c->pressed == c->hovered && c->pressed != c->selected) {
        on_panel_select(c->pressed);
        on_panel_unselect(c->selected);
        c->selected = c->pressed;
    }
    c->pressed = NULL;
}
