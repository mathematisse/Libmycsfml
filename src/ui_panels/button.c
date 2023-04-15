/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include "ui_panels/button.h"
#include "theme.h"

static panel_button_t *button_create(void)
{
    panel_button_t *bpanel = malloc(sizeof(panel_button_t));

    if (!bpanel)
        return NULL;
    bpanel->text = NULL;
    bpanel->texture = NULL;
    bpanel->on_enter = NULL;
    bpanel->on_exit = NULL;
    bpanel->on_press = NULL;
    bpanel->on_release = NULL;
    bpanel->on_select = NULL;
    bpanel->on_unselect = NULL;
    return bpanel;
}

panel_t *panel_text_button_create(
    rectransform_t *rect,
    const char *str,
    sfFont *font,
    ptype_t type)
{
    panel_button_t *bpanel = button_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, type, bpanel);
    if (!panel)
        return NULL;
    panel->text = sfText_create();
    if (str && font) {
        sfText_setFont(panel->text, font);
        sfText_setString(panel->text, str);
        sfText_setCharacterSize(panel->text, 20);
    }
    panel->shape = sfRectangleShape_create();
    if (panel->shape)
        sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    bpanel->text = str;
    return panel;

}

panel_t *panel_image_button_create(
    rectransform_t *rect,
    sfTexture *texture,
    ptype_t type)
{
    panel_button_t *bpanel = button_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, type, bpanel);
    if (!panel)
        return NULL;
    if (texture){
        panel->sprite = sfSprite_create();
        sfSprite_setTexture(panel->sprite, texture, sfTrue);
        sfSprite_setScale(panel->sprite, (sfVector2f){0.3, 0.3});
    }
    panel->shape = sfRectangleShape_create();
    if (panel->shape)
        sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    bpanel->texture = texture;
    return panel;
}

void panel_button_destroy(panel_t *panel)
{
    panel_button_t *bpanel = NULL;

    if (!panel)
        return;
    bpanel = (panel_button_t *)panel->data;
    if (!bpanel)
        return;
    if (bpanel->text)
        free((void *)bpanel->text);
    if (bpanel->texture)
        sfTexture_destroy(bpanel->texture);
    free(bpanel);
    panel_destroy(panel);
}

void butt_set_foos(panel_t *p, button_foo_t select, button_foo_t unselect)
{
    panel_button_t *bpanel = NULL;

    if (!p)
        return;
    bpanel = (panel_button_t *)p->data;
    bpanel->on_select = select;
    bpanel->on_unselect = unselect;
}
