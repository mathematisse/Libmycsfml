/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Header for the rectangle transform
*/

#ifndef RECTRANSFORM_H
    #define RECTRANSFORM_H
    #include <SFML/Graphics.h>

typedef enum anchor_type {
    ANCHOR_NONE,
    ANCHOR_START,
    ANCHOR_MIDDLE,
    ANCHOR_END
} anchor_type_t;

typedef enum resize_type {
    RESIZE_NONE,
    RESIZE_X,
    RESIZE_Y,
    RESIZE_XY
} resize_type_t;

typedef struct rectransform_s {
    sfVector2f pos;
    sfVector2f size;
    anchor_type_t xanchor;
    anchor_type_t yanchor;
    resize_type_t resize;
} rectransform_t;

rectransform_t *rectransform_create(void);
void rectransform_destroy(rectransform_t *);
sfVector2f pos_transform_rect(rectransform_t *, sfVector2f *, sfVector2f *);
sfVector2f size_transform_rect(rectransform_t *, sfVector2f *);

#endif /* RECTRANSFORM_H */
