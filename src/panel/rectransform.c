/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for rectransform
*/

#include <stdlib.h>
#include "panel/rectransform.h"

rectransform_t *rectransform_create(void)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = (sfVector2f){0, 0};
    rect->size = (sfVector2f){0, 0};
    rect->xanchor = ANCHOR_NONE;
    rect->yanchor = ANCHOR_NONE;
    rect->resize = RESIZE_NONE;
    return rect;
}

void rectransform_destroy(rectransform_t *rect)
{
    if (rect)
        free(rect);
}

sfVector2f pos_transform_rect(
    rectransform_t *rect,
    sfVector2f *parentpos,
    sfVector2f *parentsize)
{
    if (!rect || !parentpos || !parentsize)
        return (sfVector2f){0, 0};
    sfVector2f pos = rect->pos;

    if (rect->xanchor == ANCHOR_START)
        pos.x += parentpos->x;
    if (rect->xanchor == ANCHOR_MIDDLE)
        pos.x += parentpos->x + parentsize->x / 2;
    if (rect->xanchor == ANCHOR_END)
        pos.x += parentpos->x + parentsize->x;
    if (rect->yanchor == ANCHOR_START)
        pos.y += parentpos->y;
    if (rect->yanchor == ANCHOR_MIDDLE)
        pos.y += parentpos->y + parentsize->y / 2;
    if (rect->yanchor == ANCHOR_END)
        pos.y += parentpos->y + parentsize->y;
    return pos;
}

sfVector2f size_transform_rect(rectransform_t *rect, sfVector2f *psize)
{
    sfVector2f size;

    if (!rect || !psize)
        return (sfVector2f){0, 0};
    size = rect->size;
    if (rect->resize == RESIZE_X || rect->resize == RESIZE_XY)
        size.x = psize->x - rect->size.x;
    if (rect->resize == RESIZE_Y || rect->resize == RESIZE_XY)
        size.y = psize->y - rect->size.y;
    return size;
}
