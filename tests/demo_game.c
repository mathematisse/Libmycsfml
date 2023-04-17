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
    rectransform_t *mrect = rtrans_create_centered(
        (sfVector2f){-150, 113}, (sfVector2f){200, 100});
    mrect->xanchor = ANCHOR_END;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, sfColor_fromRGB(255, 255, 200));
    return main;
}

panel_t *toaster(void)
{
    rectransform_t *mrect = rtrans_create_bardown(
        (sfVector2f){0, -100}, (sfVector2f){300, 100});
    panel_t *main = panel_empty_create(mrect, sfGreen);
    return main;
}

panel_t *centerdraw(void)
{
    rectransform_t *mrect = rtrans_create_centered(
        (sfVector2f){0, 0}, (sfVector2f){300, 300});
    panel_t *main = panel_empty_create(mrect, sfWhite);

    return main;
}

panel_t *center_panel(void)
{
    rectransform_t *mrect = rtrans_create_resize(
        (sfVector2f){0, 0}, (sfVector2f){150, 150});
    panel_t *main = panel_empty_create(mrect, sfYellow);
    return main;
}

panel_t *left_bar(void)
{
    rectransform_t *mrect = rtrans_create_barleft(
        (sfVector2f){25, 0}, (sfVector2f){50, 0});
    panel_t *main = panel_empty_create(mrect, sfBlue);
    return main;
}

panel_t * top_bar(void)
{
    rectransform_t *mrect = rtrans_create_barup(
        (sfVector2f){0, 25}, (sfVector2f){0, 50});
    panel_t *main = panel_empty_create(mrect, sfRed);
    return main;
}

panel_t *demogame(void)
{
    rectransform_t *mrect =
        rtrans_create_resize((sfVector2f){0, 0}, (sfVector2f){0, 0});
    panel_t *main = panel_empty_create(mrect, sfBlack);
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
