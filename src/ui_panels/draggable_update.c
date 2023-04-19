/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include <string.h>
#include "ui_panels/draggable.h"
#include "ui_panels/slider.h"
#include "theme.h"
#include "tools.h"
#include "program.h"

void on_drag_update(panel_t *panel)
{
    panel_slider_t *spanel;
    panel_drag_t *dpanel = (panel_drag_t *)panel->data;
    float percent = (dpanel->offset.x - dpanel->bounds.left)
        / dpanel->bounds.width;
    if (dpanel->parent && dpanel->parent->type == PANEL_TYPE_SLIDER) {
        spanel = (panel_slider_t *)dpanel->parent->data;
        if (spanel && spanel->foo)
            spanel->foo(spanel->trgt, percent);
    }
}

void on_drag_move(panel_t *panel, sfVector2f newoffset)
{
    panel_drag_t *dpanel = NULL;

    if (!panel)
        return;
    dpanel = (panel_drag_t *)panel->data;
    if (!dpanel)
        return;
    dpanel->offset = (sfVector2f){newoffset.x - dpanel->parent->pos.x,
        newoffset.y - dpanel->parent->pos.y};
    clamp(&(dpanel->offset.x), dpanel->bounds.left,
        dpanel->bounds.left + dpanel->bounds.width);
    clamp(&(dpanel->offset.y), dpanel->bounds.top,
        dpanel->bounds.top + dpanel->bounds.height);
    panel->rect->pos = (sfVector2f){
        dpanel->offset.x, dpanel->offset.y};
    panel_resize(panel, &(dpanel->parent->pos), &(dpanel->parent->size));
    on_drag_update(panel);
}
