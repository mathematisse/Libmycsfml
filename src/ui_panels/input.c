/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for input panels
*/

#include <stdlib.h>
#include "program.h"
#include "ui_panels/input.h"
#include "tools.h"

static void set_panel_to_input(panel_t *panel, sfFont *font)
{
    if (!panel)
        return;
    panel->shape = sfRectangleShape_create();
    if (panel->shape) {
        sfRectangleShape_setFillColor(panel->shape, sfWhite);
        sfRectangleShape_setOutlineColor(panel->shape, sfBlack);
        sfRectangleShape_setOutlineThickness(panel->shape, 3);
    }
    panel->text = sfText_create();
    if (panel->text && font) {
        sfText_setFont(panel->text, font);
        sfText_setCharacterSize(panel->text, 16);
        sfText_setColor(panel->text, sfBlack);
        sfText_setString(panel->text, "10");
    }
}

static void set_ipanel_to_input(panel_input_t *ipanel)
{
    if (!ipanel)
        return;
    ipanel->left = ipanel->max_size - 2;
    ipanel->text = malloc(sizeof(char) * (ipanel->max_size + 1));
    if (!ipanel->text)
        return;
    ipanel->text[0] = '1';
    ipanel->text[1] = '0';
    for (int i = 2; i < ipanel->max_size; i++)
        ipanel->text[i] = '\0';
}

panel_t *panel_input_create(
    rectransform_t *rect,
    sfFont *font,
    entry_type_t type)
{
    panel_input_t *ipanel = malloc(sizeof(panel_input_t));
    panel_t *panel = NULL;

    if (!ipanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_INPUT, ipanel);
    if (!panel)
        return NULL;
    set_panel_to_input(panel, font);
    ipanel->type = type;
    ipanel->max_size = type == EntryTypeNumber ? 4 : 0;
    set_ipanel_to_input(ipanel);
    return panel;
}

void on_text_entered(sfTextEvent t, panel_t *panel)
{
    panel_input_t *input = (panel_input_t *)panel->data;

    if (input->type != EntryTypeNumber)
        return;
    if (t.unicode >= '0' && t.unicode <= '9' && input->left > 0) {
        input->text[input->max_size - input->left] = t.unicode;
        input->left--;
    } else if (t.unicode == '\b' && input->left < 4) {
        input->left++;
        input->text[input->max_size - input->left] = '\0';
    }
    sfText_setString(panel->text, input->text);
    *(input->trgt_int) = fast_atoi(input->text);
}
