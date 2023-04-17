/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program
*/

#include <stdlib.h>
#include "program.h"
#include "theme.h"

program_t *create_program(program_maker_t maker)
{
    program_t *prog = malloc(sizeof(program_t));

    if (!prog)
        return NULL;
    prog->pstate = Created;
    prog->window = NULL;
    prog->cursor = cursor_create();
    prog->scenes = maker();
    prog->current_scene = -1;
    prog->font = sfFont_createFromFile("ressources/Lato-Bold.ttf");
    return prog;
}

void destroy_program(program_t *p)
{
    if (!p)
        return;
    if (p->window)
        sfRenderWindow_destroy(p->window);
    if (p->cursor)
        cursor_destroy(p->cursor);
    if (p->scenes)
        scenes_destroy(p->scenes);
    sfFont_destroy(p->font);
    free(p);
}
