/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Foos for dropdowns
*/

#include "panel.h"

void dds_select(void *data)
{
    if (!data)
        return;
    panel_t *panel = (panel_t *)data;
    if (!panel->childs || !panel->childs[0])
        return;
    panel->childs[0]->state = PANEL_STATE_ACTIVE;
}

void dds_unselect(void *data)
{
    if (!data)
        return;
    panel_t *panel = (panel_t *)data;
    if (!panel->childs || !panel->childs[0])
        return;
    panel->childs[0]->state = PANEL_STATE_INACTIVE;
}
