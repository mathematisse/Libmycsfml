/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include <stdlib.h>
#include "theme.h"
#include "ui_panels/empty.h"
#include "tools.h"

panel_t *msg(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){200, 100};
    mrect->pos = (sfVector2f){-150, 112.5};
    mrect->xanchor = ANCHOR_END;
    mrect->yanchor = ANCHOR_START;
    mrect->resize = RESIZE_NONE;
    panel_t *main = panel_empty_create(mrect, sfColor_fromRGB(255, 255, 200));
    main->state = PANEL_STATE_ACTIVE;
    return main;
}

panel_t *toaster(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){300, 100};
    mrect->pos = (sfVector2f){0, -100};
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_END;
    mrect->resize = RESIZE_X;
    panel_t *main = panel_empty_create(mrect, sfGreen);
    main->state = PANEL_STATE_ACTIVE;
    return main;
}

panel_t *centerdraw(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){300, 300};
    mrect->pos = (sfVector2f){0, 0};
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_MIDDLE;
    mrect->resize = RESIZE_NONE;
    panel_t *main = panel_empty_create(mrect, sfWhite);
    main->state = PANEL_STATE_ACTIVE;
    return main;
}

panel_t *center_panel(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){150, 150};
    mrect->pos = (sfVector2f){0, 0};
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_MIDDLE;
    mrect->resize = RESIZE_XY;
    panel_t *main = panel_empty_create(mrect, sfYellow);
    main->state = PANEL_STATE_ACTIVE;
    return main;
}

panel_t *left_bar(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){50, 0};
    mrect->pos = (sfVector2f){25, 0};
    mrect->xanchor = ANCHOR_START;
    mrect->yanchor = ANCHOR_MIDDLE;
    mrect->resize = RESIZE_Y;
    panel_t *main = panel_empty_create(mrect, sfBlue);
    main->state = PANEL_STATE_ACTIVE;
    return main;
}

panel_t * top_bar(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){0, 50};
    mrect->pos = (sfVector2f){0, 25};
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_START;
    mrect->resize = RESIZE_X;
    panel_t *main = panel_empty_create(mrect, sfRed);
    main->state = PANEL_STATE_ACTIVE;
    return main;
}

panel_t *demogame(void)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){0, 0};
    mrect->pos = (sfVector2f){0, 0};
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_MIDDLE;
    mrect->resize = RESIZE_XY;
    panel_t *main = panel_empty_create(mrect, sfBlack);
    main->state = PANEL_STATE_ACTIVE;
    panel_t **childs = malloc(sizeof(panel_t *) * 7);
    childs[0] = top_bar();
    childs[1] = left_bar();
    childs[2] = toaster();
    childs[3] = msg();
    childs[4] = centerdraw();
    childs[5] = center_panel();
    childs[6] = NULL;
    main->childs = childs;
    main->childs_count = 6;
    return main;
}
