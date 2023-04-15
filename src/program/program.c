/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program
*/

#include <stdlib.h>
#include "program.h"

void loop_program(program_t *p)
{
    switch (p->pstate) {
    case Created:
        break;
    case Started:
        loop_objects(p);
        break;
    case Paused:
        break;
    case End:
        p->pstate = Quit;
        break;
    case Quit:
        sfRenderWindow_close(p->window);
        break;
    default:;
    }
}

void destroy_program(program_t *p)
{
    if (!p)
        return;
    if (p->window)
        sfRenderWindow_destroy(p->window);
    if (p->panel)
        panel_destroy(p->panel);
    sfFont_destroy(p->font);
    free(p);
}

int execute_program(panel_t *(*create_panel)(void))
{
    program_t *prog = NULL;

    prog = create_program(create_panel);
    if (!prog)
        return EXIT_FAILURE;
    if (start_program(prog)) {
        destroy_program(prog);
        return EXIT_FAILURE;
    }
    while (sfRenderWindow_isOpen(prog->window))
        loop_program(prog);
    destroy_program(prog);
    return EXIT_SUCCESS;
}
