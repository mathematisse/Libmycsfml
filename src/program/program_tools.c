/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** extra functions for the csfml program
*/

#include <stdio.h>
#include "program.h"
#include "panel/panel_event.h"
#include "ui_panels/input.h"
#include "theme.h"

static void resize_event(program_t *p)
{
    sfSizeEvent e = p->event.size;
    sfView *view = NULL;
    sfVector2f pos = { -((float) e.width) / 2, -((float) e.height) / 2 };
    sfVector2f size = { e.width, e.height };

    view = sfView_createFromRect((sfFloatRect) {0, 0, e.width, e.height });
    sfRenderWindow_setView(p->window, view);
    panel_resize(p->panel, &pos, &size);
}

int switch_game_event(program_t *p)
{
    sfEvent e = p->event;
    switch (e.type) {
    case sfEvtClosed: sfRenderWindow_close(p->window); return -1;
    case sfEvtResized: resize_event(p); break;
    case sfEvtTextEntered:
        if (p->selected && p->selected->type == PANEL_TYPE_INPUT)
            on_text_entered(e.text, p->selected);
        break;
    default: return switch_cursor_event(p);
    }
    return 0;
}

void loop_hover(program_t *p)
{
    if (!p || !p->panel || !p->board)
        return;
    panel_t *hovered =
        get_hovered_panel(p->panel, &(sfVector2i) {p->cursor.x, p->cursor.y});
    if (hovered != p->hovered) {
        if (p->hovered != p->selected)
            on_panel_leave(p->hovered);
        if (hovered != p->selected)
            on_panel_enter(hovered);
        p->hovered = hovered;
    }
}

void loop_objects(program_t *p)
{
    while (sfRenderWindow_pollEvent(p->window, &(p->event)))
        if (switch_game_event(p) == -1)
            return;
    sfRenderWindow_clear(p->window, CLEAR_COLOR);
    panel_draw(p->window, p->panel);
    loop_hover(p);
    sfRenderWindow_display(p->window);
}
