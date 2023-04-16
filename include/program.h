/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for program object
*/

#ifndef PROGRAM_H
    #define PROGRAM_H
    #include "scene.h"
    #include "cursor.h"

enum program_state {
    Created,
    Started,
    Paused,
    End,
    Quit
};

typedef struct program_s {
    enum program_state pstate;
    sfRenderWindow *window;
    sfEvent event;
    cursor_t cursor;
    scene_t **scenes;
    sfFont *font;
} program_t;

program_t *create_program(program_maker_t maker);
int start_program(program_t *h);
void loop_program(program_t *p);
void destroy_program(program_t *h);
int execute_program(panel_t *(*create_panel)(void));

int switch_game_event(program_t *h);
int switch_cursor_event(program_t *h);
void loop_objects(program_t *h);

#endif /* PROGRAM_H */
