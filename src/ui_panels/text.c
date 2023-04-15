/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for empty panels
*/

#include <stdlib.h>
#include "ui_panels/text.h"

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
    panel->text = sfText_create();
    if (panel->text && font && str) {
        sfText_setFont(panel->text, font);
        sfText_setString(panel->text, str);
        sfText_setCharacterSize(panel->text, 16);
        sfText_setColor(panel->text, sfWhite);
    }
    return panel;
}

void panel_text_destroy(panel_t *panel)
{
    if (!panel)
        return;
    free((panel_text_t *)panel->data);
    panel_destroy(panel);
}
