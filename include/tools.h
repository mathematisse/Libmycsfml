/*
** EPITECH PROJECT, 2022
** Libmycsfml
** File description:
** Header for tools
*/

#ifndef TOOLS_H
    #define TOOLS_H

int is_interactable(ptype_t t);
int fast_atoi(const char *str);
void save_as_png(sfTexture* texture, const char* path);
char *str(const char *str, int i);
#endif /* TOOLS_H */
