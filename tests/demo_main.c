/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdlib.h>
#include <unistd.h>
#include "program.h"
#include "theme.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "tools.h"

panel_t *demogame(void);
panel_t *demomenu(program_t *p);

scene_t **demo_scenes(program_t *p)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 3);
    panel_t **panels = malloc(sizeof(panel_t *) * 2);
    panel_t **mpanels = malloc(sizeof(panel_t *) * 2);

    if (!scenes || !panels || !mpanels)
        return NULL;
    mpanels[0] = demomenu(p);
    mpanels[1] = NULL;
    panels[0] = demogame();
    panels[1] = NULL;
    scenes[0] = scene_create(mpanels, NULL);
    scenes[1] = scene_create(panels, NULL);
    scenes[2] = NULL;
    scenes[0]->settings = (scene_settings_t) {
        .size = (sfVector2u) {1920, 1080},
        .title = "Demo Menu",
        .style = sfClose | sfResize | sfTitlebar
    };
    scenes[1]->settings = (scene_settings_t) {
        .size = (sfVector2u) {1920, 1080},
        .title = "Demo Demo"
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
