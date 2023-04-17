/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdlib.h>
#include <unistd.h>
#include "program.h"
#include "theme.h"

panel_t *demopanel(void);

scene_t **demo_scenes(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 2);
    panel_t **panels = malloc(sizeof(panel_t *) * 2);

    if (!scenes || !panels)
        return NULL;
    panels[0] = demopanel();
    panels[1] = NULL;
    scenes[0] = scene_create(panels, NULL);
    scenes[1] = NULL;
    scenes[0]->settings = (scene_settings_t) {
        .size = (sfVector2u) {1920, 1080},
        .title = "Demo",
        .style = sfClose | sfResize | sfTitlebar
    };
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
