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

panel_t *demopanel(void);

void change_scene(void *data)
{
    program_t *program = (program_t *) data;
    (void) start_scene(program, 1);
}

static panel_t *create_start_button(program_t *p)
{
    rectransform_t *sb_rect = rectransform_create();
    sb_rect->size = (sfVector2f){200, 100};
    sb_rect->pos = (sfVector2f){0, -75};
    sb_rect->xanchor = ANCHOR_MIDDLE;
    sb_rect->yanchor = ANCHOR_MIDDLE;
    sb_rect->resize = RESIZE_NONE;
    panel_t *start_butt =
        panel_text_button_create(sb_rect, str("Start", 5), p->font, PTYPE_EVBUTT);
    start_butt->state = PANEL_STATE_ACTIVE;
    start_butt->childs = NULL;
    start_butt->childs_count = 0;
    ((panel_button_t *)start_butt->data)->trgt = p;
    butt_set_foos(start_butt, change_scene, NULL);
    return start_butt;
}

void quit_program(void *data)
{
    program_t *program = (program_t *) data;
    program->pstate = Quit;
}

static panel_t *creat_quit_button(program_t *p)
{
    rectransform_t *sb_rect = rectransform_create();
    sb_rect->size = (sfVector2f){200, 100};
    sb_rect->pos = (sfVector2f){0, 75};
    sb_rect->xanchor = ANCHOR_MIDDLE;
    sb_rect->yanchor = ANCHOR_MIDDLE;
    sb_rect->resize = RESIZE_NONE;
    panel_t *start_butt =
        panel_text_button_create(sb_rect, str("Quit", 4), p->font, PTYPE_EVBUTT);
    start_butt->state = PANEL_STATE_ACTIVE;
    start_butt->childs = NULL;
    start_butt->childs_count = 0;
    ((panel_button_t *)start_butt->data)->trgt = p;
    butt_set_foos(start_butt, quit_program, NULL);
    return start_butt;
}

panel_t *demomenu(program_t *p)
{
    rectransform_t *mrect = rectransform_create();
    mrect->size = (sfVector2f){0, 0};
    mrect->pos = (sfVector2f){0, 0};
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_MIDDLE;
    mrect->resize = RESIZE_XY;
    panel_t *pmain = panel_empty_create(mrect, sfBlack);
    pmain->state = PANEL_STATE_ACTIVE;
    panel_t **childs = malloc(sizeof(panel_t *) * 3);
    childs[0] = create_start_button(p);
    childs[1] = creat_quit_button(p);
    childs[2] = NULL;
    pmain->childs = childs;
    pmain->childs_count = 2;
    return pmain;
}
