/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program start
*/

#include <stdlib.h>
#include "program.h"

int start_first_scene(program_t *p)
{
    scene_settings_t settings = p->scenes[0]->settings;
    sfVideoMode mode = {settings.size.x, settings.size.y, 32};

    p->current_scene = 0;
    p->window = sfRenderWindow_create(mode, settings.title,
        settings.style, NULL);
    if (!(p->window))
        return EXIT_FAILURE;
    p->fullscreen = 0;
    sfRenderWindow_setFramerateLimit(p->window, 60);
    resize_event(p, (sfSizeEvent)
        {.width = settings.size.x, .height = settings.size.y});
    return EXIT_SUCCESS;
}

int start_scene(program_t *p, int i)
{
    scene_settings_t settings = p->scenes[i]->settings;
    sfVector2f pos = { -((float) settings.size.x) / 2,
        -((float) settings.size.y) / 2 };

    p->current_scene = i;
    if (!(p->window))
        return EXIT_FAILURE;
    sfRenderWindow_setTitle(p->window, settings.title);
    if (p->fullscreen) {
        canvas_resize(p->scenes[p->current_scene]->canvas,
            &(sfVector2f){p->size.x / 2, p->size.y / 2},
            &(sfVector2f){p->size.x, p->size.y});
        resize_event(p, (sfSizeEvent)
            {.width = p->size.x, .height = p->size.y});
        return EXIT_SUCCESS;
    }
    sfRenderWindow_setSize(p->window, settings.size);
    canvas_resize(p->scenes[p->current_scene]->canvas,
        &pos, &(sfVector2f){settings.size.x, settings.size.y});
    resize_event(p, (sfSizeEvent)
        {.width = settings.size.x, .height = settings.size.y});
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
