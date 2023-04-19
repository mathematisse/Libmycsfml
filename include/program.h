/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for program object
*/

#ifndef PROGRAM_H
    #define PROGRAM_H
    #define WRULE sfClose | sfResize | sfTitlebar
    #define WNAME "Libmycsfml"
    #define WDEPTH 32
    #include <SFML/Audio.h>
    #include "scene.h"
    #include "cursor.h"
    #define INVENTORYX 8
    #define INVENTORYY 5


enum program_state {
    Created,
    Started,
    Paused,
    End,
    Quit
};

typedef struct prog_param_s {
    int width;
    int height;
    int fullscreen;
    float scale;
    char *user;
    float music_volume;
    float sound_volume;
} prog_param_t;

typedef struct user_s {
    int credit;
    int score;
    int level;
    float walk_speed;
    float reload_speed;
    float life;
    int inventory[INVENTORYX][INVENTORYY][2];
} user_t;

typedef struct program_s {
    prog_param_t params;
    enum program_state pstate;
    sfRenderWindow *window;
    cursor_t *cursor;
    scene_t **scenes;
    int current_scene;
    sfFont *font;
    sfMusic *music;
} program_t;

typedef scene_t **(*program_maker_t)(program_t *);

program_t *create_program(program_maker_t maker);
void destroy_program(program_t *p);
int start_program(program_t *p);
int start_scene(program_t *p, int i);
int execute_program(program_maker_t maker);
int loop_events(program_t *p);
void resize_event(program_t *p, sfSizeEvent e);

panel_t *paramenuflex(program_t *p);
void load_hyperparams(prog_param_t *params, const char* path);
void save_hyperparams(prog_param_t *params, const char* path);
#endif /* PROGRAM_H */
