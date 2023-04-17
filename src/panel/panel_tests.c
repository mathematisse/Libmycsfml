/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Main function for my_paint
*/

#include <stdlib.h>
#include "panel/panel.h"

int is_interactable(ptype_t t)
{
    if (t == PTYPE_DDBUTT ||
        t == PTYPE_EVBUTT ||
        t == PANEL_TYPE_INPUT)
        return 1;
    return 0;
}
