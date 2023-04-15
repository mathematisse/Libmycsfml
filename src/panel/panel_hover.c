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

void on_panel_enter(panel_t *panel)
{
    if (!panel)
        return;
    if (is_concerned(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_HOVER);
    }
}

void on_panel_leave(panel_t *panel)
{
    if (!panel)
        return;
    if (is_concerned(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    }
}

void on_panel_pressed(panel_t *panel)
{
    if (!panel)
        return;
    if (is_concerned(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_PRESS);
    }
}

void on_panel_released(panel_t *panel)
{
    if (!panel)
        return;
    if (is_concerned(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_HOVER);
    }
}
