/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include <string.h>
#include "ui_panels/draggable.h"
#include "theme.h"
#include "tools.h"
#include "program.h"

panel_t *make_drag(sfVector2f pos)
{
    sfVector2f size = {15, 40};
    rectransform_t *sb_rect = rtrans_create_centered(pos, size);
    sb_rect->xanchor = ANCHOR_START;
    sb_rect->yanchor = ANCHOR_START;
    panel_t *drag = panel_item_drag_create(sb_rect, PANEL_TYPE_DRAG);

    return drag;
}

void on_drag_move(panel_t *panel, sfVector2f newoffset)
{
    panel_drag_t *dpanel = NULL;

    if (!panel)
        return;
    dpanel = (panel_drag_t *)panel->data;
    if (!dpanel)
        return;
    dpanel->offset = newoffset;
    clamp(&(dpanel->offset.x), dpanel->bounds.left,
        dpanel->bounds.left + dpanel->bounds.width);
    clamp(&(dpanel->offset.y), dpanel->bounds.top,
        dpanel->bounds.top + dpanel->bounds.height);
    panel->rect->pos = (sfVector2f){
        dpanel->offset.x + dpanel->initpos.x,
        dpanel->offset.y + dpanel->initpos.y};
    panel_resize(panel, &(sfVector2f){0, 0}, &(sfVector2f){1920, 1080});
}

panel_drag_t *drag_create(void)
{
    panel_drag_t *dpanel = malloc(sizeof(panel_drag_t));

    if (!dpanel)
        return NULL;
    dpanel->offset = (sfVector2f){0, 0};
    dpanel->bounds = (sfFloatRect){0, 0, 0, 0};
    dpanel->initpos = (sfVector2f){0, 0};
    return dpanel;
}

panel_t *panel_item_drag_create(
    rectransform_t *rect,
    ptype_t type)
{
    panel_drag_t *bpanel = drag_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, type, bpanel);
    if (!panel)
        return NULL;
    init_rshape(&(panel->shape), HANDLES);
    bpanel->initpos = rect->pos;
    bpanel->bounds = (sfFloatRect){-100, 0, 200, 0};
    return panel;
}

void panel_drag_destroy(panel_t *panel)
{
    panel_drag_t *dpanel = NULL;

    if (!panel)
        return;
    dpanel = (panel_drag_t *)panel->data;
    if (!dpanel)
        return;
    free(dpanel);
    panel_destroy(panel);
}
