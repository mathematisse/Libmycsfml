/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program
*/

#include <stdlib.h>
#include "program.h"
#include "theme.h"

static void destroy_program(program_t *p)
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

static void loop_program(program_t *p)
{
    scene_t *scene = NULL;
    if (loop_events(p) == -1)
        return;
    sfRenderWindow_clear(p->window, CLEAR_COLOR);
    scene = p->scenes[p->current_scene];
    scene_loop(p->window, scene, 0);
    scene_draw(p->window, scene);
    sfRenderWindow_display(p->window);
}

static void switch_program_state(program_t *p)
{
    switch (p->pstate) {
    case Created: break;
    case Started: loop_program(p); break;
    case Paused: break;
    case End: p->pstate = Quit; break;
    case Quit: sfRenderWindow_close(p->window); break;
    default: break;
    }
}

int execute_program(program_maker_t maker)
{
    program_t *prog = NULL;

    prog = create_program(maker);
    if (!prog)
        return EXIT_FAILURE;
    if (start_program(prog) == EXIT_FAILURE) {
        destroy_program(prog);
        return EXIT_FAILURE;
    }
    while (sfRenderWindow_isOpen(prog->window))
        switch_program_state(prog);
    destroy_program(prog);
    return EXIT_SUCCESS;
}
