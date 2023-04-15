/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program start
*/

#include <stdlib.h>
#include "program.h"
#include "theme.h"

program_t *create_program(panel_t *(*create_panel)(void))
{
    program_t *prog = malloc(sizeof(program_t));

    if (!prog)
        return NULL;
    prog->pstate = Created;
    prog->window = NULL;
    prog->event = (sfEvent) { 0 };
    prog->font = sfFont_createFromFile("ressources/Lato-Bold.ttf");
    prog->panel = create_panel();
    prog->hovered = NULL;
    prog->pressed = NULL;
    prog->selected = NULL;
    return prog;
}

int start_program(program_t *p)
{
    sfVideoMode mode = { 1920, 1080, 32 };

    p->window = sfRenderWindow_create(
        mode,
        "Mathematisse CSFML Template",
        sfResize | sfClose | sfTitlebar,
        NULL);
    if (!(p->window))
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(p->window, 60);
    p->pstate = Started;
    sfVector2f pos = { -960, -540 };
    sfVector2f size = { 1920, 1080 };
    panel_resize(p->panel, &pos, &size);
    return EXIT_SUCCESS;
}
