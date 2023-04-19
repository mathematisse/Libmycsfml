/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include "program.h"
#include "ui_panels/flex.h"
#include "ui_panels/text.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/empty.h"
#include "tools.h"
#include "ui_panels/buttallfoos.h"
#include "theme.h"

void start_esc_pressed(scene_t *s)
{
    panel_t *mainp = s->canvas->panels[0];
    panel_t *startp = mainp->childs[1];

    if (startp->state == PANEL_STATE_ACTIVE) {
        startp->state = PANEL_STATE_INACTIVE;
    } else {
        startp->state = PANEL_STATE_ACTIVE;
    }
    mainp->childs[1]->state = PANEL_STATE_INACTIVE;
    mainp->childs[2]->state = PANEL_STATE_INACTIVE;
}

void mopen_options(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[0]->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_INACTIVE;
    panels[1]->state = PANEL_STATE_ACTIVE;
}

void mopen_cmds(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[0]->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_INACTIVE;
    panels[2]->state = PANEL_STATE_ACTIVE;
}

static panel_t *menuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 6}, (sfVector2f){210, 60});
    panel_add_childs(fmain, 6,
        make_label(p->font, "Save Name:"),
        make_name_input(p->font, &(p->params.user)),
        make_butt("Start", p, change_scene, p->font),
        make_butt("Options", p, mopen_options, p->font),
        make_butt("Commands", p, mopen_cmds, p->font),
        make_butt("Quit", p, quit_program, p->font)
    );
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

panel_t *startmenu(program_t *p)
{
    rectransform_t *mrect = rtrans_create_resize();
    panel_t *pmain = panel_none_create(mrect);

    panel_add_childs(pmain, 2, menuflex(p), paramenuflex(p));
    return pmain;
}
