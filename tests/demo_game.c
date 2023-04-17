/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include <stdlib.h>
#include "theme.h"
#include "ui_panels/flex.h"
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

panel_t *quick_access(void)
{
    panel_t *fmain = make_flex((sfVector2i){3, 1}, (sfVector2f){110, 110});
    fmain->rect->pos.y = -120;
    fmain->rect->yanchor = ANCHOR_END;
    panel_add_childs(fmain, 3,
        panel_empty_create(rtrans_create_flexelem((sfVector2f){0, 0}, (sfVector2f){100, 100}), sfRed),
        panel_empty_create(rtrans_create_flexelem((sfVector2f){0, 0}, (sfVector2f){100, 100}), sfGreen),
        panel_empty_create(rtrans_create_flexelem((sfVector2f){0, 0}, (sfVector2f){100, 100}), sfBlue));
    init_rshape(&(fmain->shape), sfWhite);
    return fmain;
}

panel_t *toaster(void)
{
    rectransform_t *mrect = rtrans_create_bardown(
        (sfVector2f){0, -100}, (sfVector2f){300, 100});
    panel_t *main = panel_empty_create(mrect, sfGreen);
    panel_add_childs(main, 1, quick_access());
    return main;
}

panel_t *centerdraw(void)
{
    return panel_empty_create(
        rtrans_create_centered(
            (sfVector2f){0, 0},
            (sfVector2f){300, 300}),
        sfWhite);
}

panel_t *center_panel(void)
{
    return panel_empty_create(
        rtrans_create_resize(
            (sfVector2f){0, 0},
            (sfVector2f){400, 400}),
        sfYellow);
}

panel_t *left_bar(float width)
{
    return panel_empty_create(
        rtrans_create_barleft(
            (sfVector2f){width / 2, 0},
            (sfVector2f){width, 0}),
        sfBlue);
}

panel_t * top_bar(float height)
{
    return panel_empty_create(
        rtrans_create_barup(
            (sfVector2f){0, height / 2},
            (sfVector2f){0, height}),
        sfRed);
}

panel_t *demogame(void)
{
    rectransform_t *mrect =
        rtrans_create_resize((sfVector2f){0, 0}, (sfVector2f){0, 0});
    panel_t *main = panel_empty_create(mrect, sfBlack);
    panel_add_childs(main, 6,
        top_bar(100),
        left_bar(200),
        quick_access(),
        msg(),
        centerdraw(),
        center_panel());
    return main;
}
