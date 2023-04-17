/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Resizing foos for panel
*/

#include <stdio.h>
#include "panel.h"

static void sprite_rect_set(panel_t *panel)
{
    sfVector2f sprite_pos = {0, 0};
    sfFloatRect sprite_size = sfSprite_getGlobalBounds(panel->sprite);

    sprite_pos.x = panel->pos.x + (panel->size.x - sprite_size.width) / 2;
    sprite_pos.y = panel->pos.y + (panel->size.y - sprite_size.height) / 2;
    sfSprite_setPosition(panel->sprite, sprite_pos);
}

static void text_rect_set(panel_t *panel)
{
    sfVector2f text_pos;

    text_pos.x = panel->pos.x + 5;
    text_pos.y = panel->pos.y;
    sfText_setPosition(panel->text, text_pos);
}

static void panel_rect_set(panel_t *panel)
{
    if (!panel)
        return;
    if (panel->shape) {
        sfRectangleShape_setSize(panel->shape, panel->size);
        sfRectangleShape_setPosition(panel->shape, panel->pos);
    }
    if (panel->sprite) {
        sprite_rect_set(panel);
    }
    if (panel->text) {
        text_rect_set(panel);
    }
}

void panel_resize(panel_t *panel, sfVector2f *pos, sfVector2f *size)
{
    if (!panel)
        return;
    panel->pos = pos_transform_rect(panel->rect, pos, size);
    panel->size = size_transform_rect(panel->rect, size);
    for (int i = 0; i < panel->childs_count; i++)
        panel_resize(panel->childs[i], &(panel->pos), &(panel->size));
    panel_rect_set(panel);
}
