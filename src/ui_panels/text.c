/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for empty panels
*/

#include <stdlib.h>
#include "ui_panels/text.h"
#include "tools.h"
#include "ui_panels/flex.h"
panel_t *make_label(sfFont *font, const char *str)
{
    rectransform_t *rect = rtrans_create_flexelem((sfVector2f){200, 50});
    return panel_text_create(rect, font, str);
}

panel_t *make_label_pair(sfFont *font, const char *str, panel_t *panel)
{
    panel_t *epanel = make_flex((sfVector2i){2, 1}, (sfVector2f){210, 60});
    panel_add_childs(epanel, 2, make_label(font, str), panel);
    epanel->rect->xanchor = ANCHOR_START;
    epanel->rect->yanchor = ANCHOR_START;
    return epanel;
}

panel_t *text_create(sfFont *font, const char *str, rectransform_t *rect)
{
    panel_t *text = panel_text_create(rect, font, str);
    text->state = PANEL_STATE_ACTIVE;
    return text;
}

panel_t *panel_text_create(rectransform_t *rect, sfFont *font, const char *str)
{
    panel_text_t *tpanel = malloc(sizeof(panel_text_t));
    panel_t *panel = NULL;

    if (!tpanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_TEXT, tpanel);
    if (!panel)
        return NULL;
    panel->shape = NULL;
    init_text(&panel->text, font, str);
    return panel;
}

void panel_text_destroy(panel_t *panel)
{
    if (!panel)
        return;
    free((panel_text_t *)panel->data);
    panel_destroy(panel);
}
