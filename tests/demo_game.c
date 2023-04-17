/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include <stdlib.h>
#include "demo.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"
#include "ui_panels/buttallfoos.h"

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
        panel_empty_create(rtrans_create_flexelem((sfVector2f){100, 100}), sfBlack),
        panel_empty_create(rtrans_create_flexelem((sfVector2f){100, 100}), sfBlack),
        panel_empty_create(rtrans_create_flexelem((sfVector2f){100, 100}), sfBlack));
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
    panel_t *fmain = make_flex((sfVector2i){1, 8}, (sfVector2f){210, 60});
    panel_add_childs(fmain, 8,
        create_continue_button(p),
        create_inventory_button(p),
        create_stats_button(p),
        create_save_button(p),
        create_load_button(p),
        create_options_button(p),
        create_cmds_button(p),
        create_gquit_button(p)
    );
    init_rshape(&(fmain->shape), sfBlue);
    fmain->state = PANEL_STATE_INACTIVE;
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
    rectransform_t *mrect = rtrans_create_resize();
    mrect->xanchor = ANCHOR_START;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, sfTransparent);
    panel_add_childs(main, 3,
        left_bar(200),
        quick_access(),
        minimap());
    return main;
}

panel_t *invmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){85, 85});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), sfBlack);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), sfWhite);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
panel_t *statmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){75, 75});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), sfBlack);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), sfWhite);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
panel_t *paramenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){75, 75});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), sfBlack);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), sfWhite);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
panel_t *cmdmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){75, 75});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), sfBlack);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), sfWhite);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
panel_t *demogame(program_t *p)
{
    rectransform_t *mrect = rtrans_create_resize();
    panel_t *main = panel_none_create(mrect);
    panel_add_childs(main, 6, game_interface(), escmenuflex(p), invmenuflex(p), statmenuflex(p), paramenuflex(p), cmdmenuflex(p));
    return main;
}