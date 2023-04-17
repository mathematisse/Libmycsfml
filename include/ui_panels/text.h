/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for text panels
*/

#ifndef TEXT_H
    #define TEXT_H
    #include "panel.h"

typedef struct panel_text_s {
    const char *text;
} panel_text_t;

panel_t *panel_text_create(rectransform_t *rect, sfFont *font, const char *str);
void panel_text_destroy(panel_t *panel);

panel_t *text_create(sfFont *font, const char *str, rectransform_t *rect);
#endif /* TEXT_H */
