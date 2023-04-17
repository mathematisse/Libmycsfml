/*
** EPITECH PROJECT, 2023
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
    cursor_t *cursor;
    scene_t **scenes;
    int current_scene;
    sfFont *font;
} program_t;

typedef scene_t **(*program_maker_t)(program_t *);

program_t *create_program(program_maker_t maker);
void destroy_program(program_t *p);
int start_program(program_t *p);
int start_scene(program_t *p, int i);
int execute_program(program_maker_t maker);
int loop_events(program_t *p);
void resize_event(program_t *p, sfSizeEvent e);
#endif /* PROGRAM_H */
