/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for mouse event management
*/

#include <stdlib.h>
#include "program.h"
#include "panel/panel_event.h"

static void mouse_moved(program_t *p)
{
    p->cursor.x = p->event.mouseMove.x;
    p->cursor.y = p->event.mouseMove.y;
}

static void mouse_pressed(program_t *p)
{
    p->pressed = p->hovered;
    if (p->pressed != p->selected)
        on_panel_pressed(p->pressed);
}

static void mouse_released(program_t *p)
{
    if (p->pressed != p->selected)
        on_panel_released(p->pressed);
    if (p->pressed == p->hovered && p->pressed != p->selected) {
        on_panel_select(p->pressed, p);
        on_panel_unselect(p->selected);
        p->selected = p->pressed;
    }
    p->pressed = NULL;
}

int switch_cursor_event(program_t *p)
{
    sfEvent e = p->event;

    switch (e.type) {
    case sfEvtMouseMoved:
        mouse_moved(p); break;
    case sfEvtMouseButtonPressed:
        mouse_pressed(p); break;
    case sfEvtMouseButtonReleased:
        mouse_released(p); break;
    default: ;
    }
    return 0;
}
