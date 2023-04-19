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
content_t *demo_content_maker(void);
panel_t *game_interface(void);
#endif /* DEMO_H */
