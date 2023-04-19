/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <stdlib.h>
#include "demo.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"
#include "ui_panels/buttallfoos.h"
#include "ui_panels/draggable.h"
#include "theme.h"
#include "ui_panels/options.h"

panel_t *invmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){85, 85});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), ITEM_BG);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}

panel_t *statmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){75, 75});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), ITEM_BG);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}

panel_t *cmdmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){8, 4}, (sfVector2f){75, 75});
    panel_t **childs = malloc(sizeof(panel_t) * 8 * 4 + 1);
    for (int i = 0; i < 8 * 4; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem((sfVector2f){75, 75}), ITEM_BG);
    childs[8 * 4] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 8 * 4;
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}

panel_t *demogame(program_t *p)
{
    rectransform_t *mrect = rtrans_create_resize();
    panel_t *main = panel_none_create(mrect);
    panel_add_childs(main, 6, game_interface(), escmenuflex(p),
        invmenuflex(p), statmenuflex(p), paramenuflex(p), cmdmenuflex(p));
    return main;
}
