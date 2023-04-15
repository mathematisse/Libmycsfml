/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** General foos for panels
*/

#include "ui_panels/button.h"
#include "program.h"
#include "theme.h"
#include "tools.h"

void on_panel_select(panel_t *panel, program_t *p)
{
    if (!panel)
        return;
    if (is_concerned(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_SELECT);
    }
    if (panel->type == PTYPE_DDBUTT) {
        panel_button_t *bpanel = (panel_button_t *)panel->data;
        if (bpanel->on_select)
            bpanel->on_select(panel);
    }
    if (panel->type == PTYPE_EVBUTT) {
        panel_button_t *bpanel = (panel_button_t *)panel->data;
        if (bpanel->on_select)
            bpanel->on_select(p);
    }
}

void on_panel_unselect(panel_t *panel)
{
    if (!panel)
        return;
    if (is_concerned(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    }
    if (panel->type == PTYPE_DDBUTT) {
        panel_button_t *bpanel = (panel_button_t *)panel->data;
        if (bpanel->on_unselect)
            bpanel->on_unselect(panel);
    }
}
