/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include "program.h"
#include "ui_panels/draggable.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "ui_panels/empty.h"
#include "tools.h"
#include "theme.h"
#include "ui_panels/button.h"
#include "ui_panels/options.h"
#include "ui_panels/dropdown.h"
#include "ui_panels/slider.h"

panel_t *resolution_dd(sfFont *font, program_t *prog)
{
    panel_t *panel = make_dd(4, (sfVector2f){210, 60});
    panel_add_childs(panel, 4,
        make_butt("1920 X 1080", prog, set_high_resol, font),
        make_butt("1280 X 720", prog, set_medium_resol, font),
        make_butt("800 X 600", prog, set_low_resol, font),
        make_butt("400 X 300", prog, set_mini_resol, font));
    return panel;
}

static panel_t *resol_dd_butt(sfFont *font, program_t *prog)
{
    panel_t *panel = make_ddbutt(font, "1920 X 1080");
    panel_add_childs(panel, 1, resolution_dd(font, prog));
    return panel;
}

void update_music_volume(void *in, float value)
{
    program_t *prog = (program_t *)in;
    prog->params.music_volume = value;
    sfMusic_setVolume(prog->music,
        value * VOLRANGE + MUSICVOLUME - VOLRANGE / 2);
}

void update_sound_volume(void *in, float value)
{
    program_t *prog = (program_t *)in;
    canvas_t *c = prog->scenes[prog->current_scene]->canvas;

    prog->params.sound_volume = value;
    sfSound_setVolume(c->soundppress,
        value * VOLRANGE + SOUNDVOLUME - VOLRANGE / 2);
    sfSound_setVolume(c->soundprelease,
        value * VOLRANGE + SOUNDVOLUME - VOLRANGE / 2);
}

panel_t *paramenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 6}, (sfVector2f){440, 70});
    panel_add_childs(fmain, 6,
        make_label(p->font, "Video"),
        make_label_pair(p->font, "Fullscreen",
            make_butt("Toggle", p, toggle_fullscreen, p->font)),
        make_label_pair(p->font, "Resolution", resol_dd_butt(p->font, p)),
        make_label(p->font, "Audio"),
        make_label_pair(p->font, "Music",
            make_slider(p, update_music_volume)),
        make_label_pair(p->font, "Sound",
            make_slider(p, update_sound_volume)));
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
