/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for content object
*/

#ifndef CONTENT_H
    #define CONTENT_H
    #include "canvas.h"

typedef void *(*content_maker_t)(void);
typedef void (*content_destroyer_t)(void *);
typedef void (*content_drawer_t)(sfRenderWindow *, void *);
typedef void (*content_looper_t)(void *, float);
typedef void (*content_eventer_t)(void *, sfEvent);
typedef void (*content_on_enter_t)(void *);
typedef void (*content_on_leave_t)(void *);
typedef void (*content_on_press_t)(void *, sfMouseButtonEvent);
typedef void (*content_on_release_t)(void *, sfMouseButtonEvent);
typedef void (*content_on_select_t)(void *);
typedef void (*content_on_deselect_t)(void *);
typedef void (*content_on_hover_t)(void *, sfVector2i *);
typedef void (*content_on_key_press_t)(void *, sfKeyEvent);
typedef void (*content_on_key_release_t)(void *, sfKeyEvent);

typedef struct content_s {
    void *content;
    content_maker_t maker;
    content_destroyer_t destroyer;
    content_drawer_t drawer;
    content_looper_t looper;
    content_eventer_t eventer;
    content_on_enter_t on_enter;
    content_on_leave_t on_leave;
    content_on_press_t on_press;
    content_on_release_t on_release;
    content_on_select_t on_select;
    content_on_deselect_t on_deselect;
    content_on_hover_t on_hover;
    content_on_key_press_t on_key_press;
    content_on_key_release_t on_key_release;
} content_t;

#endif /* CONTENT_H */
