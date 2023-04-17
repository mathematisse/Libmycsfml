/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for demo
*/

#ifndef DEMO_H
    #define DEMO_H
    #define HELP_TEXT "DEMO\nUSAGE\n\t./demo\nInfo:\n\tLaunch csfml demo\n"
    #include "program.h"

panel_t *demogame(program_t *p);
panel_t *demomenu(program_t *p);

panel_t *create_start_button(program_t *p);
panel_t *create_quit_button(program_t *p);
panel_t *create_continue_button(program_t *p);

content_t *demo_content_maker(void);
#endif /* DEMO_H */
