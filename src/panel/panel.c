/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for panels
*/

#include <stdlib.h>
#include "panel/panel.h"

panel_t *panel_create(rectransform_t *rect, ptype_t type, void *data)
{
    panel_t *panel = malloc(sizeof(panel_t));
    if (!panel)
        return NULL;
    panel->shape = NULL;
    panel->sprite = NULL;
    panel->text = NULL;
    panel->type = type;
    panel->state = PANEL_STATE_ACTIVE;
    panel->data = data;
    panel->rect = rect;
    panel->pos =
        pos_transform_rect(rect, &(sfVector2f){0, 0}, &(sfVector2f){0, 0});
    panel->size = size_transform_rect(rect, &(sfVector2f){0, 0});
    panel->childs = NULL;
    panel->childs_count = 0;
    return panel;
}

void panel_destroy(panel_t *panel)
{
    if (!panel)
        return;
    for (int i = 0; i < panel->childs_count; i++)
        panel_destroy(panel->childs[i]);
    free(panel);
}

void panel_add_childs(panel_t *parent, panel_t **childs, int nb_childs)
{
    if (!parent || !childs)
        return;
    parent->childs = childs;
    parent->childs_count = nb_childs;
}

void panel_draw(sfRenderWindow *window, panel_t *panel)
{
    if (!panel || !window)
        return;
    if (panel->state == PANEL_STATE_INACTIVE)
        return;
    if (panel->shape)
        sfRenderWindow_drawRectangleShape(window, panel->shape, NULL);
    if (panel->sprite)
        sfRenderWindow_drawSprite(window, panel->sprite, NULL);
    if (panel->text)
        sfRenderWindow_drawText(window, panel->text, NULL);
    for (int i = panel->childs_count - 1; i >= 0; i--)
        panel_draw(window, panel->childs[i]);
}

panel_t *get_hovered_panel(panel_t *panel, sfVector2i *pos)
{
    panel_t *hovered = NULL;
    sfFloatRect rect = {0, 0, 0, 0};

    if (!panel || !pos || panel->state == PANEL_STATE_INACTIVE)
        return NULL;
    rect = (sfFloatRect) {
        (int)panel->pos.x,
        (int)panel->pos.y,
        (int)panel->size.x,
        (int)panel->size.y};
    for (int i = 0; i < panel->childs_count; i++) {
        hovered = get_hovered_panel(panel->childs[i], pos);
        if (hovered)
            break;
    }
    if (!hovered && sfFloatRect_contains(&rect, pos->x, pos->y))
        hovered = panel;
    return hovered;
}
