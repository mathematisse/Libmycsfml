/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for panels' event
*/

#ifndef PANEL_EVENT_H
    #define PANEL_EVENT_H
    #include "panel.h"
    #include "program.h"

void on_panel_enter(panel_t *panel);
void on_panel_leave(panel_t *panel);
void on_panel_pressed(panel_t *panel);
void on_panel_released(panel_t *panel);
void on_panel_select(panel_t *panel);
void on_panel_unselect(panel_t *panel);

#endif /* PANEL_EVENT_H */
