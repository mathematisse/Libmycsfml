/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for program object
*/

#ifndef PROGRAM_H
    #define PROGRAM_H
    #include "panel/panel.h"

enum program_state {
    Created,
    Started,
    Paused,
    End,
    Quit
};

typedef struct cursor_s {
    int x;
    int y;
} cursor_t;

typedef struct Program {
    enum program_state pstate;
    sfRenderWindow *window;
    sfEvent event;
    cursor_t cursor;
    sfFont *font;
    panel_t *panel;
    panel_t *hovered;
    panel_t *pressed;
    panel_t *selected;
    panel_t *board;
} program_t;

program_t *create_program(panel_t *(*create_panel)(void));
int start_program(program_t *h);
void loop_program(program_t *p);
void destroy_program(program_t *h);
int execute_program(panel_t *(*create_panel)(void));

void loop_clock(program_t *h);
int switch_game_event(program_t *h);
int switch_cursor_event(program_t *h);
void loop_objects(program_t *h);

#endif /* PROGRAM_H */
