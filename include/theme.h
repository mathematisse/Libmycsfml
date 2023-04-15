/*
** PERSONNAL PROJECT, 2022
** Libmycsfml
** File description:
** Header for all defined colors
*/

#ifndef THEME_H
    #define THEME_H
    #include <SFML/Graphics.h>
    #include "panel/panel.h"

    #define HELP_TEXT "CSFML DEMO\nUSAGE\n\t./demo\nInfo:\n\tLaunch csfml demo\n"
    #define BUTTON_BASE sfColor_fromRGB(100, 100, 100)
    #define BUTTON_HOVER sfColor_fromRGB(125, 125, 125)
    #define BUTTON_PRESS sfColor_fromRGB(150, 150, 150)
    #define BUTTON_SELECT sfColor_fromRGB(200, 200, 200)
    #define CLEAR_COLOR sfColor_fromRGB(0, 0, 0)
    #define LEFT_BARS sfColor_fromRGB(50, 50, 100)
    #define FRAME_BASE sfColor_fromRGBA(0, 0, 0, 0)
    #define BACKGROUND sfColor_fromRGB(50, 50, 50)
    #define TOP_BAR sfColor_fromRGB(100, 100, 100)

panel_t *demopanel(void);
#endif /* THEME_H */
