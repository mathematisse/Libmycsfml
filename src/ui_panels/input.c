/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for input panels
*/

#include <stdlib.h>
#include "program.h"
#include "ui_panels/input.h"
#include "tools.h"

static void init_ipanel(panel_input_t *ipanel, entry_type_t type)
{
    if (!ipanel)
        return;
    ipanel->type = type;
    switch (type) {
        case EntryTypeNumber: ipanel->max_size = 4; break;
        case EntryTypeLetter: ipanel->max_size = 10; break;
    }
    ipanel->left = ipanel->max_size;
    ipanel->text = str("0", ipanel->max_size);
    for (int i = 0; i < ipanel->max_size; i++)
        ipanel->text[i] = '\0';
}

panel_t *panel_input_create(
    rectransform_t *rect,
    sfFont *font,
    entry_type_t type)
{
    panel_input_t *ipanel = malloc(sizeof(panel_input_t));
    panel_t *panel = NULL;
    sfFloatRect trect;

    if (!ipanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_INPUT, ipanel);
    if (!panel)
        return NULL;
    init_rshape(&panel->shape, sfWhite);
    init_text(&panel->text, font, "");
    trect = sfText_getLocalBounds(panel->text);
    sfText_setOrigin(panel->text, (sfVector2f){
        trect.left + trect.width / 2.0f, panel->rect->size.y / 7.0f});
    sfText_setColor(panel->text, sfBlack);
    init_ipanel(ipanel, type);
    return panel;
}

void on_num_ipanel_entry(sfTextEvent t, panel_input_t *input)
{
    if (t.unicode >= '0' && t.unicode <= '9' && input->left > 0) {
        input->text[input->max_size - input->left] = t.unicode;
        input->left--;
    } else if (t.unicode == '\b' && input->left < 4) {
        input->left++;
        input->text[input->max_size - input->left] = '\0';
    }
    *(input->trgt_int) = fast_atoi(input->text);
}

void on_text_ipanel_entry(sfTextEvent t, panel_input_t *input)
{
    if (t.unicode >= 'a' && t.unicode <= 'z' && input->left > 0) {
        input->text[input->max_size - input->left] = t.unicode;
        input->left--;
    } else if (t.unicode == '\b' && input->left < 10) {
        input->left++;
        input->text[input->max_size - input->left] = '\0';
    }
    *(input->trgt_str) = input->text;
}

void on_text_entered(sfTextEvent t, panel_t *panel)
{
    panel_input_t *input = (panel_input_t *)panel->data;
    sfFloatRect trect;
    switch (input->type) {
        case EntryTypeNumber: on_num_ipanel_entry(t, input); break;
        case EntryTypeLetter: on_text_ipanel_entry(t, input); break;
        default: break;
    }
    sfText_setString(panel->text, input->text);
    trect = sfText_getLocalBounds(panel->text);
    sfText_setOrigin(panel->text, (sfVector2f){
        trect.left + trect.width / 2.0f, panel->rect->size.y / 7.0f});
}
