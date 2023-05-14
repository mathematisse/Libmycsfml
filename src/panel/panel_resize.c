/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Resizing foos for panel
*/

#include <stdio.h>
#include "panel.h"
#include "ui_panels/flex.h"
#include "ui_panels/draggable.h"

static void sprite_rect_set(panel_t *panel)
{
    sfVector2f sprite_pos = {0, 0};
    sfFloatRect sprite_size = sfSprite_getGlobalBounds(panel->data);

    sprite_pos.x = panel->pos.x + (panel->size.x - sprite_size.width) / 2;
    sprite_pos.y = panel->pos.y + (panel->size.y - sprite_size.height) / 2;
    sfSprite_setPosition(panel->data, sprite_pos);
}

static void text_rect_set(panel_t *panel, float scale)
{
    sfFloatRect trect;

    sfText_setCharacterSize(panel->data, (unsigned int) 20.0 * scale);
    trect = sfText_getLocalBounds(panel->data);
    sfText_setOrigin(panel->data, (sfVector2f){
        trect.left + trect.width / 2.0f, panel->size.y / 2.0f});
    sfText_setPosition(panel->data, panel->pos);
}

static void shape_rect_set(panel_t *panel)
{
    sfRectangleShape_setSize(panel->data, panel->size);
    sfRectangleShape_setOrigin(panel->data,
        (sfVector2f){panel->size.x / 2, panel->size.y / 2});
    sfRectangleShape_setPosition(panel->data, panel->pos);
}

static void panel_rect_set(panel_t *panel, float scale)
{
    if (!panel)
        return;
    switch (panel->type) {
        case PANEL_T_SHAPE: shape_rect_set(panel); break;
        case PANEL_T_SPRITE: sprite_rect_set(panel); break;
        case PANEL_T_TEXT: text_rect_set(panel, scale); break;
    }
}

void panel_resize(
    panel_t *panel, sfVector2f *pos, sfVector2f *size, float scale)
{
    if (!panel || !pos || !size)
        return;
    if (panel->type == PANEL_TYPE_DRAG)
        drag_repos(panel, scale);
    panel->pos = rtrans_pos_update(panel->rect, pos, size);
    if (panel->rect->resize == RESIZE_X || panel->rect->resize == RESIZE_XY)
        panel->pos.x = 0;
    if (panel->rect->resize == RESIZE_Y || panel->rect->resize == RESIZE_XY)
        panel->pos.y = 0;
    if (panel->type == PANEL_TYPE_FLEX)
        panel_flex_update(panel);
    panel->size = rtrans_size_update(panel->rect, size, scale);
    for (int i = 0; i < panel->childs_count; i++)
        panel_resize(panel->childs[i], &(panel->pos), &(panel->size), scale);
    panel_rect_set(panel, scale);
    if (panel->type == PANEL_TYPE_FLEX)
        panel_flex_repos(panel, scale);
}
