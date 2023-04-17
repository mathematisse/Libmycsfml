/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdio.h>
#include "program.h"

void change_scene(void *data)
{
    program_t *program = (program_t *) data;
    (void) start_scene(program, program->current_scene + 1);
}

void quit_program(void *data)
{
    program_t *program = (program_t *) data;
    program->pstate = Quit;
}

void quit_game(void *data)
{
    program_t *program = (program_t *) data;
    (void) start_scene(program, 0);
}

void continue_program(void *data)
{
    program_t *program = (program_t *) data;
    scene_t *scene = program->scenes[program->current_scene];
    panel_t **panels = scene->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_ACTIVE;
    panels[1]->state = PANEL_STATE_INACTIVE;
    scene->content->state = CONTENT_STATE_PLAY;
}

void open_inventory(void *data)
{
    program_t *program = (program_t *) data;
    panel_t **panels = program->scenes[program->current_scene]->canvas->panels[0]->childs;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[2]->state = PANEL_STATE_ACTIVE;
}

void open_stats(void *data)
{
    program_t *program = (program_t *) data;
    panel_t **panels = program->scenes[program->current_scene]->canvas->panels[0]->childs;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[3]->state = PANEL_STATE_ACTIVE;
}

void save_content(void *data)
{
    printf("Saving content !\n");
}

void load_content(void *data)
{
    printf("Loading content !\n");
}

void open_options(void *data)
{
    panel_t **panels = (panel_t **) data;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[4]->state = PANEL_STATE_ACTIVE;
}

void open_cmds(void *data)
{
    panel_t **panels = (panel_t **) data;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[5]->state = PANEL_STATE_ACTIVE;
}

