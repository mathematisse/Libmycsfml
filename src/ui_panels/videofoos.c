/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Base functions for video options
*/

#include "program.h"

void set_high_resol(void *p)
{
    program_t *prog = (program_t *)p;
    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, 60);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){1920, 1080});
}

void set_medium_resol(void *p)
{
    program_t *prog = (program_t *)p;
    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){1280, 720, 32},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, 60);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){1280, 720});
}

void set_low_resol(void *p)
{
    program_t *prog = (program_t *)p;
    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){800, 600, 32},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, 60);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){800, 600});
}

void set_mini_resol(void *p)
{
    program_t *prog = (program_t *)p;
    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){400, 300, 32},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, 60);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){400, 300});
}

void toggle_fullscreen(void *data)
{
    program_t *p = (program_t *)data;
    p->params.fullscreen = !p->params.fullscreen;
    sfRenderWindow_destroy(p->window);
    p->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        WNAME, WRULE | (p->params.fullscreen ? sfFullscreen : 0), NULL);
    sfRenderWindow_setFramerateLimit(p->window, 60);
    if (p->params.fullscreen)
        return;
    set_medium_resol(p);
}
