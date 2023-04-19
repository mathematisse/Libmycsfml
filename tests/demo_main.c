/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <unistd.h>
#include <stdlib.h>
#include "demo.h"

scene_t **demo_scenes(program_t *p)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 3);
    panel_t **panels = malloc(sizeof(panel_t *) * 2);
    panel_t **mpanels = malloc(sizeof(panel_t *) * 2);

    if (!scenes || !panels || !mpanels)
        return NULL;
    mpanels[0] = demomenu(p);
    mpanels[1] = NULL;
    panels[0] = demogame(p);
    panels[1] = NULL;
    scenes[0] = scene_create(mpanels, NULL);
    scenes[1] = scene_create(panels, demo_content_maker());
    scenes[2] = NULL;
    return scenes;
}

int show_help(void)
{
    write(1, HELP_TEXT, sizeof(HELP_TEXT));
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            return show_help();
        return 84;
    }
    return execute_program(demo_scenes);
}
