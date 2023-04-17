/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** extra functions for the csfml program
*/

#include <stdlib.h>
#include "scene.h"
#include "canvas.h"

scene_t *scene_create(panel_t **panels, void *content)
{
    scene_t *scene = NULL;
    canvas_t *canvas = NULL;

    canvas = canvas_create(panels);
    if (!canvas)
        return NULL;
    scene = malloc(sizeof(scene_t));
    if (!scene)
        return NULL;
    scene->canvas = canvas;
    scene->content = content;
    return scene;
}

static void scene_destroy(scene_t *scene)
{
    if (!scene)
        return;
    canvas_destroy(scene->canvas);
    free(scene);
}

void scenes_destroy(scene_t **scenes)
{
    for (int i = 0; scenes[i]; i++)
        scene_destroy(scenes[i]);
    free(scenes);
}
