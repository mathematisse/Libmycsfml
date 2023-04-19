/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include <string.h>
#include "ui_panels/slider.h"
#include "ui_panels/empty.h"
#include "ui_panels/draggable.h"
#include "theme.h"
#include "tools.h"

panel_t *make_slider(void *trgt, slider_foo_t foo)
{
    rectransform_t *rect = rtrans_create_flexelem((sfVector2f){200, 50});
    panel_t *epanel = panel_slider_create(rect);
    panel_add_childs(epanel, 2, make_handle_drag((sfVector2f){0, 0}, epanel),
        panel_empty_create(
            rtrans_create_flexelem((sfVector2f){200, 10}), ITEM_BG));
    panel_slider_t *spanel = (panel_slider_t *)epanel->data;
    spanel->trgt = trgt;
    spanel->foo = foo;
    return epanel;
}

static panel_slider_t *slider_create(void)
{
    panel_slider_t *bpanel = malloc(sizeof(panel_slider_t)); 

    if (!bpanel)
        return NULL;
    bpanel->trgt = NULL;
    bpanel->foo = NULL;
    return bpanel;
}

panel_t *panel_slider_create(rectransform_t *rect)
{
    panel_slider_t *bpanel = slider_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_SLIDER, bpanel);
    if (!panel)
        return NULL;
    init_rshape(&(panel->shape), BUTTON_BASE);
    return panel;
}

void panel_slider_destroy(panel_t *panel)
{
    panel_slider_t *bpanel = NULL;

    if (!panel)
        return;
    bpanel = (panel_slider_t *)panel->data;
    if (!bpanel)
        return;
    free(bpanel);
    panel_destroy(panel);
}
