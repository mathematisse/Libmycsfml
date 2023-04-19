/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Factory foos for canvases
*/

#include <SFML/Audio.h>
#include "stdlib.h"
#include "canvas.h"
#include "theme.h"

canvas_t *canvas_create(panel_t **panels)
{
    canvas_t *canvas = NULL;

    if (!panels || !panels[0])
        return NULL;
    canvas = malloc(sizeof(canvas_t));
    if (!canvas)
        return NULL;
    canvas->panels = panels;
    canvas->hovered = NULL;
    canvas->pressed = NULL;
    canvas->selected = NULL;
    canvas->spbuf = sfSoundBuffer_createFromFile("ressources/clickpress.ogg");
    canvas->soundppress = sfSound_create();
    sfSound_setBuffer(canvas->soundppress, canvas->spbuf);
    sfSound_setVolume(canvas->soundppress, SOUNDVOLUME);
    canvas->srbuf = sfSoundBuffer_createFromFile("ressources/clickrelease.ogg");
    canvas->soundprelease = sfSound_create();
    sfSound_setBuffer(canvas->soundprelease, canvas->srbuf);
    sfSound_setVolume(canvas->soundprelease, SOUNDVOLUME);
    return canvas;
}

void canvas_destroy(canvas_t *canvas)
{
    for (int i = 0; canvas->panels[i]; i++)
        panel_destroy(canvas->panels[i]);
    sfSoundBuffer_destroy(canvas->spbuf);
    sfSoundBuffer_destroy(canvas->srbuf);
    sfSound_destroy(canvas->soundppress);
    sfSound_destroy(canvas->soundprelease);
    free(canvas);
}
