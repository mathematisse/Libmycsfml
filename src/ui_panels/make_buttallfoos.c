/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"
#include "string.h"
#include "program.h"
#include "ui_panels/buttallfoos.h"

panel_t *create_start_button(program_t *p)
{
    return make_butt("Start", p, change_scene, p->font);
}

panel_t *create_quit_button(program_t *p)
{
    return make_butt("Quit", p, quit_program, p->font);
}

panel_t *create_gquit_button(program_t *p)
{
    return make_butt("Main Menu", p, quit_game, p->font);
}

panel_t *create_continue_button(program_t *p)
{
    return make_butt("Continue", p, continue_program, p->font);
}

panel_t *create_inventory_button(program_t *p)
{
    return make_butt("Inventory", p, open_inventory, p->font);
}

panel_t *create_stats_button(program_t *p)
{
    return make_butt("Stats", p, open_stats, p->font);
}

panel_t *create_save_button(program_t *p)
{
    return make_butt("Save", p, save_content, p->font);
}

panel_t *create_load_button(program_t *p)
{
    return make_butt("Load", p, load_content, p->font);
}

panel_t *create_options_button(program_t *p)
{
    return make_butt("Options", p, open_options, p->font);
}

panel_t *create_cmds_button(program_t *p)
{
    return make_butt("Commands", p, open_cmds, p->font);
}
