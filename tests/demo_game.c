/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include "demo.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"

panel_t *minimap(void)
{
    rectransform_t *mrect = rtrans_create_centered(
        (sfVector2f){-200, 200}, (sfVector2f){200, 200});
    mrect->xanchor = ANCHOR_END;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, sfBlack);
    return main;
}

panel_t *quick_access(void)
{
    panel_t *fmain = make_flex((sfVector2i){3, 1}, (sfVector2f){110, 110});
    fmain->rect->pos.y = -120;
    fmain->rect->yanchor = ANCHOR_END;
    panel_add_childs(fmain, 3,
        panel_empty_create(rtrans_create_flexelem((sfVector2f){0, 0}, (sfVector2f){100, 100}), sfBlack),
        panel_empty_create(rtrans_create_flexelem((sfVector2f){0, 0}, (sfVector2f){100, 100}), sfBlack),
        panel_empty_create(rtrans_create_flexelem((sfVector2f){0, 0}, (sfVector2f){100, 100}), sfBlack));
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

panel_t *escmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 2}, (sfVector2f){300, 120});
    panel_add_childs(fmain, 2,
        create_continue_button(p),
        create_quit_button(p)
    );
    init_rshape(&(fmain->shape), sfBlue);
    return fmain;
}

panel_t *left_bar(float width)
{
    return panel_empty_create(
        rtrans_create_barleft(
            (sfVector2f){width / 2, 0},
            (sfVector2f){width, 0}),
        sfBlack);
}

panel_t *game_interface(void)
{
    rectransform_t *mrect =
        rtrans_create_resize((sfVector2f){0, 0}, (sfVector2f){0, 0});
    mrect->xanchor = ANCHOR_START;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, sfTransparent);
    panel_add_childs(main, 3,
        left_bar(200),
        quick_access(),
        minimap());
    return main;
}

panel_t *demogame(program_t *p)
{
    rectransform_t *mrect =
        rtrans_create_resize((sfVector2f){0, 0}, (sfVector2f){0, 0});
    panel_t *main = panel_none_create(mrect);
    panel_add_childs(main, 2, escmenuflex(p), game_interface());
    main->childs[0]->state = PANEL_STATE_INACTIVE;
    return main;
}