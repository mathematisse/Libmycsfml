/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for panels
*/

#ifndef PANEL_H
    #define PANEL_H
    #include "rectransform.h"

typedef enum panel_type {
    PANEL_TYPE_NONE,
    PANEL_TYPE_EMPTY,
    PANEL_TYPE_FLEX,
    PANEL_TYPE_INPUT,
    PANEL_TYPE_BOARD,
    PANEL_TYPE_TEXT,
    PTYPE_DDBUTT,
    PTYPE_EVBUTT,
    PANEL_TYPE_IMAGE
} ptype_t;

typedef enum panel_state {
    PANEL_STATE_NONE,
    PANEL_STATE_ACTIVE,
    PANEL_STATE_INACTIVE
} pstate_t;

typedef struct panel_s panel_t;
struct panel_s {
    sfRectangleShape *shape;
    sfSprite *sprite;
    sfText *text;
    ptype_t type;
    pstate_t state;
    void *data;
    rectransform_t *rect;
    sfVector2f pos;
    sfVector2f size;
    panel_t **childs;
    int childs_count;
};

panel_t *panel_create(rectransform_t *rect, ptype_t type, void *data);
void panel_add_childs(panel_t *panel, panel_t **childs, int count);

void panel_destroy(panel_t *panel);

void panel_resize(panel_t *panel, sfVector2f *pos, sfVector2f *size);
void panel_draw(sfRenderWindow *window, panel_t *panel);

panel_t *get_hovered_panel(panel_t *panel, sfVector2i *pos);

#endif /* PANEL_H */
