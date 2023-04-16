/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for scene object
*/

#ifndef SCENE_H
    #define SCENE_H
    #include "canvas.h"


typedef struct scene_s {
    canvas_t *canvas;
    void *content;
} scene_t;

typedef scene_t **(*program_maker_t)(void);

scene_t *create_scene(canvas_t *canvas, void *content);
void destroy_scene(scene_t *scene);
void destroy_scenes(scene_t **scenes);


#endif /* SCENE_H */
