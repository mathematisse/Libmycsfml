/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Demo content
*/

#include <stdio.h>
#include <stdlib.h>
#include "content.h"

void demo_content_destroyer(void *content)
{
    printf("Demo content destroyer called\n");
}

void demo_content_eventer(void *content, sfEvent event)
{
    printf("Demo content eventer called\n");
}

void demo_content_on_enter(void *content)
{
    printf("Demo content on enter called\n");
}

void demo_content_on_leave(void *content)
{
    printf("Demo content on leave called\n");
}

void demo_content_on_press(void *content, sfMouseButtonEvent event)
{
    printf("Demo content on press called\n");
}

void demo_content_on_release(void *content, sfMouseButtonEvent event)
{
    printf("Demo content on release called\n");
}

void demo_content_on_select(void *content)
{
    printf("Demo content on select called\n");
}

void demo_content_on_deselect(void *content)
{
    printf("Demo content on deselect called\n");
}

void demo_content_on_hover(void *content, sfVector2i *mouse)
{
    printf("Demo content on hover called\n");
}

void demo_content_on_key_press(void *content, sfKeyEvent event)
{
    printf("Demo content on key press called\n");
}

void demo_content_on_key_release(void *content, sfKeyEvent event)
{
    printf("Demo content on key release called\n");
}

void demo_content_on_start(void *content)
{
    printf("Demo content on start called\n");
}

void demo_content_on_pause(void *content)
{
    printf("Demo content on pause called\n");
}

void demo_content_on_resume(void *content)
{
    printf("Demo content on resume called\n");
}

void demo_content_on_stop(void *content)
{
    printf("Demo content on stop called\n");
}

content_t *demo_content_maker(void)
{
    content_t *content = malloc(sizeof(content_t));

    content->content = NULL;
    content->maker = demo_content_maker;
    content->destroyer = demo_content_destroyer;
    content->drawer = NULL;
    content->looper = NULL;
    content->eventer = demo_content_eventer;
    content->on_enter = demo_content_on_enter;
    content->on_leave = demo_content_on_leave;
    content->on_press = demo_content_on_press;
    content->on_release = demo_content_on_release;
    content->on_select = demo_content_on_select;
    content->on_deselect = demo_content_on_deselect;
    content->on_hover = demo_content_on_hover;
    content->on_key_press = demo_content_on_key_press;
    content->on_key_release = demo_content_on_key_release;
    content->on_start = demo_content_on_start;
    content->on_pause = demo_content_on_pause;
    content->on_resume = demo_content_on_resume;
    content->on_stop = demo_content_on_stop;
    return content;
}