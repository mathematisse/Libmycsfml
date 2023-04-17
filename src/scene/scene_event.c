/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Event foos for scenes
*/

#include "program.h"

void scene_hover(scene_t *s, sfVector2i e)
{
    if (!s)
        return;
    if (!s->content) {
        canvas_hover(s->canvas, &e);
        return;
    }
    if (s->canvas->hovered == NULL) {
        canvas_hover(s->canvas, &e);
        if (s->canvas->hovered != NULL && s->content->on_leave)
            s->content->on_leave(s->content->content);
    } else {
        canvas_hover(s->canvas, &e);
        if (s->canvas->hovered == NULL && s->content->on_enter)
            s->content->on_enter(s->content->content);
    }
    if (s->content->on_hover)
        s->content->on_hover(s->content->content, &e);
}

void scene_pressed(scene_t *s, sfMouseButtonEvent e)
{
    if (!s)
        return;
    if (e.button == sfMouseLeft)
        canvas_pressed(s->canvas, e);
    if (s->canvas->hovered == NULL && s->content && s->content->on_press)
        s->content->on_press(s->content, e);
}

void scene_released(scene_t *s, sfMouseButtonEvent e)
{
    if (!s)
        return;
    if (e.button == sfMouseLeft)
        canvas_released(s->canvas, e);
    if (s->content && s->content->on_release)
        s->content->on_release(s->content, e);
}

void scene_key_pressed(scene_t *s, sfKeyEvent e)
{
    if (!s)
        return;
    if (s->content && s->content->on_key_press)
        s->content->on_key_press(s->content, e);
}

void scene_key_released(scene_t *s, sfKeyEvent e)
{
    if (!s)
        return;
    if (s->content && s->content->on_key_release)
        s->content->on_key_release(s->content, e);
}
