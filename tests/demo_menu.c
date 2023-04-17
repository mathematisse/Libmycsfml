/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdlib.h>
#include <unistd.h>
#include "demo.h"
#include "theme.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"

panel_t *demopanel(void);

panel_t *create_name_input(sfFont *font)
{
    rectransform_t *rect = rtrans_create_flexelem(
        (sfVector2f){0, 0}, (sfVector2f){200, 50});
    panel_t *radius_input = panel_input_create(
        rect, font, EntryTypeLetter);
    return radius_input;
}

panel_t *create_name_input_label(sfFont *font)
{
    rectransform_t *rect = rtrans_create_flexelem(
        (sfVector2f){0, 0}, (sfVector2f){200, 50});
    panel_t *shape_infotext = panel_text_create(
        rect, font, "Enter your name:");
    return shape_infotext;
}

panel_t *menuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 4}, (sfVector2f){300, 120});
    panel_add_childs(fmain, 4,
        create_name_input_label(p->font),
        create_name_input(p->font),
        create_start_button(p),
        create_quit_button(p)
    );
    init_rshape(&(fmain->shape), sfBlue);
    return fmain;
}

panel_t *demomenu(program_t *p)
{
    rectransform_t *mrect = rtrans_create_resize(
        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    panel_t *pmain = panel_none_create(mrect);
    panel_add_childs(pmain, 1, menuflex(p));
    return pmain;
}
