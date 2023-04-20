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
#include "ui_panels/buttallfoos.h"

panel_t *resolution_dd(sfFont *font, program_t *prog)
{
    panel_t *panel = make_dd(4,
        (sfVector2f){ELEMX + ELEMMARGIN, ELEMY + ELEMMARGIN});
    panel_add_childs(panel, 4,
        make_butt(STRHRESOL, prog, set_high_resol, font),
        make_butt(STRMRESOL, prog, set_medium_resol, font),
        make_butt(STRLRESOL, prog, set_low_resol, font),
        make_butt(STRXSRESOL, prog, set_mini_resol, font));
    return panel;
}

static panel_t *resol_dd_butt(sfFont *font, program_t *prog)
{
    panel_t *panel = make_ddbutt(font, STRHRESOL);
    panel_add_childs(panel, 1, resolution_dd(font, prog));
    return panel;
}

panel_t *paramenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 6},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN), ELEMY + ELEMMARGIN});
    panel_add_childs(fmain, 6,
        make_label(p->font, "Video"),
        make_label_pair(p->font, "Fullscreen",
            make_butt("Toggle", p, toggle_fullscreen, p->font)),
        make_label_pair(p->font, "Resolution", resol_dd_butt(p->font, p)),
        make_label(p->font, "Audio"),
        make_label_pair(p->font, "Music", make_slider(p, update_music_volume,
            p->params.music_volume, p->params.scale)),
        make_label_pair(p->font, "Sound", make_slider(p, update_sound_volume,
            p->params.sound_volume, p->params.scale)));
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}

panel_t *escmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 8},
        (sfVector2f){ELEMX + ELEMMARGIN, ELEMY + ELEMMARGIN});
    panel_add_childs(fmain, 8,
        make_butt("Continue", p, continue_program, p->font),
        make_butt("Inventory", p, open_inventory, p->font),
        make_butt("Stats", p, open_stats, p->font),
        make_butt("Save", p, save_content, p->font),
        make_butt("Load", p, load_content, p->font),
        make_butt("Options", p, open_options, p->font),
        make_butt("Commands", p, open_cmds, p->font),
        make_butt("Main Menu", p, quit_game, p->font)
    );
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
