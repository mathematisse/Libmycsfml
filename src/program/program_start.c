/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program start
*/

#include <stdlib.h>
#include "program.h"

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

int start_first_scene(program_t *p)
{
    scene_settings_t settings = p->scenes[0]->settings;
    sfVideoMode mode = {settings.size.x, settings.size.y, 32};
    sfVector2f pos = {-settings.size.x / 2, -settings.size.y / 2};
    sfVector2f size = {(float) settings.size.x, (float) settings.size.y};

    p->current_scene = 0;
    p->window = sfRenderWindow_create(mode, settings.title,
        settings.style, NULL);
    if (!(p->window))
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(p->window, 60);
    canvas_resize(p->scenes[0]->canvas, &pos, &size);
    return EXIT_SUCCESS;
}

int start_scene(program_t *p, int i)
{
    scene_settings_t settings = p->scenes[i]->settings;
    sfVector2f pos = {-settings.size.x / 2, -settings.size.y / 2};
    sfVector2f size = {(float) settings.size.x, (float) settings.size.y};

    p->current_scene = i;
    if (!(p->window))
        return EXIT_FAILURE;
    sfRenderWindow_setTitle(p->window, settings.title);
    sfRenderWindow_setSize(p->window, settings.size);
    canvas_resize(p->scenes[i]->canvas, &pos, &size);
    return EXIT_SUCCESS;
}

int start_program(program_t *p)
{
    if (p->pstate != Created)
        return EXIT_FAILURE;
    if (start_first_scene(p) == EXIT_FAILURE)
        return EXIT_FAILURE;
    p->pstate = Started;
    return EXIT_SUCCESS;
}
