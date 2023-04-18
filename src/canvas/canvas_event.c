/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Event foos for canvases
*/

#include "ui_panels/draggable.h"
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
    if (c->pressed && c->pressed->type == PANEL_TYPE_DRAG) {
        on_drag_move(c->pressed, (sfVector2f){pos->x, pos->y});
    }
}

void canvas_pressed(canvas_t *c, sfMouseButtonEvent e)
{
    sfVector2i *pos = &(sfVector2i){e.x, e.y};
    canvas_hover(c, pos);
    c->pressed = c->hovered;
    if (c->pressed != c->selected)
        on_panel_pressed(c->pressed);
}

void canvas_released(canvas_t *c, sfMouseButtonEvent e)
{
    canvas_hover(c, &(sfVector2i){e.x, e.y});
    if (c->selected && c->pressed != c->selected
        && c->selected->type == PTYPE_DDBUTT)
        on_panel_unselect(c->selected);
    if (c->pressed != c->selected)
        on_panel_released(c->pressed);
    if (c->pressed == c->hovered && c->pressed != c->selected) {
        on_panel_select(c->pressed);
        on_panel_unselect(c->selected);
        if (c->pressed && c->pressed->type == PTYPE_EVBUTT) {
            on_panel_released(c->pressed);
            on_panel_unselect(c->selected);
            c->hovered = NULL;
            c->selected = NULL;
        } else
            c->selected = c->pressed;
    }
    c->pressed = NULL;
}
