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

panel_t *minimap(void)
{
    rectransform_t *mrect = rtrans_create_centered(
        (sfVector2f){-200, 200}, (sfVector2f){200, 200});
    mrect->xanchor = ANCHOR_END;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, ITEM_BG);
    return main;
}

panel_t *quick_access(void)
{
    panel_t *fmain = make_flex((sfVector2i){INVENTORYX, 1},
        (sfVector2f){ITEMSIZE + ELEMMARGIN, ITEMSIZE + ELEMMARGIN});
    panel_t **childs = malloc(sizeof(panel_t) * INVENTORYX + 1);
    fmain->rect->pos.y = -120;
    fmain->rect->yanchor = ANCHOR_END;
    for (int i = 0; i < INVENTORYX; i++)
        childs[i] = panel_empty_create(rtrans_create_flexelem(
            (sfVector2f){ITEMSIZE, ITEMSIZE}), ITEM_BG);
    childs[INVENTORYX] = NULL;
    fmain->childs = childs;
    fmain->childs_count = INVENTORYX;
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

panel_t *game_interface(void)
{
    rectransform_t *mrect = rtrans_create_resize();
    mrect->xanchor = ANCHOR_START;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, sfTransparent);
    panel_add_childs(main, 2, quick_access(), minimap());
    return main;
}
