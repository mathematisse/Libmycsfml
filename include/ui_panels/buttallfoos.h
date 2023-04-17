/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for button panels
*/

#ifndef BUTTALLFOOS_H
    #define BUTTALLFOOS_H
    #include "program.h"

void change_scene(void *data);
void quit_program(void *data);
void quit_game(void *data);
void continue_program(void *data);
void open_inventory(void *data);
void open_stats(void *data);
void save_content(void *data);
void load_content(void *data);
void open_options(void *data);
void open_cmds(void *data);

panel_t *create_start_button(program_t *p);
panel_t *create_quit_button(program_t *p);
panel_t *create_gquit_button(program_t *p);
panel_t *create_continue_button(program_t *p);
panel_t *create_inventory_button(program_t *p);
panel_t *create_stats_button(program_t *p);
panel_t *create_save_button(program_t *p);
panel_t *create_load_button(program_t *p);
panel_t *create_options_button(program_t *p);
panel_t *create_cmds_button(program_t *p);
#endif /* BUTTALLFOOS_H */
