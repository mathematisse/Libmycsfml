/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include "demo.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"

panel_t *demopanel(void);

void change_scene(void *data)
{
    program_t *program = (program_t *) data;
    (void) start_scene(program, 1);
}

panel_t *create_start_button(program_t *p)
{
    rectransform_t *sb_rect = rtrans_create_flexelem(
        (sfVector2f){0, 0}, (sfVector2f){200, 100});
    panel_t *start_butt = panel_text_button_create(
        sb_rect, str("Start", 5), p->font, PTYPE_EVBUTT);
    ((panel_button_t *)start_butt->data)->trgt = p;
    butt_set_foos(start_butt, change_scene, NULL);
    return start_butt;
}

void quit_program(void *data)
{
    program_t *program = (program_t *) data;
    program->pstate = Quit;
}

panel_t *create_quit_button(program_t *p)
{
    rectransform_t *sb_rect = rtrans_create_flexelem(
        (sfVector2f){0, 0}, (sfVector2f){200, 100});
    panel_t *start_butt = panel_text_button_create(
        sb_rect, str("Quit", 4), p->font, PTYPE_EVBUTT);
    ((panel_button_t *)start_butt->data)->trgt = p;
    butt_set_foos(start_butt, quit_program, NULL);
    return start_butt;
}

void continue_program(void *data)
{
    program_t *program = (program_t *) data;
    scene_t *scene = program->scenes[program->current_scene];
    panel_t **panels = scene->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_INACTIVE;
    panels[1]->state = PANEL_STATE_ACTIVE;
    scene->content->state = CONTENT_STATE_PLAY;
}

panel_t *create_continue_button(program_t *p)
{
    rectransform_t *sb_rect = rtrans_create_flexelem(
        (sfVector2f){0, 0}, (sfVector2f){200, 100});
    panel_t *start_butt = panel_text_button_create(
        sb_rect, str("Continue", 4), p->font, PTYPE_EVBUTT);
    ((panel_button_t *)start_butt->data)->trgt = p;
    butt_set_foos(start_butt, continue_program, NULL);
    return start_butt;
}