/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for empty panels
*/

#include <stdlib.h>
#include "ui_panels/flex.h"
#include "tools.h"

panel_t *panel_flex_create(rectransform_t *rect, sfVector2i counts, sfVector2f elem_size)
{
    panel_flex_t *fpanel = malloc(sizeof(panel_flex_t));
    panel_t *panel = NULL;

    if (!fpanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_FLEX, fpanel);
    if (!panel)
        return NULL;
    fpanel->counts = counts;
    fpanel->elem_size = elem_size;
    return panel;
}

void panel_flex_destroy(panel_t *panel)
{
    panel_flex_t *fpanel;

    if (!panel)
        return;
    if (panel->data) {
        fpanel = panel->data;
        free(fpanel);
    }
    panel_destroy(panel);
}

void panel_flex_repos(panel_t *panel)
{
    panel_flex_t *fpanel = panel->data;
    int ptr = 0;
    int i = 0;
    int j = 0;
    float x = 0;
    float y = 0;

    if (!panel)
        return;
    for (; ptr < panel->childs_count; ptr++) {
        x = (float)j * fpanel->elem_size.x;
        y = (float)i * fpanel->elem_size.y;
        panel->childs[ptr]->rect->pos = (sfVector2f){x, y};
        j++;
        if (j >= fpanel->counts.x) {
            j = 0;
            i++;
        }
    }
}