/*
** PERSONNAL PROJECT, 2022
** Libmycsfml
** File description:
** Header for board panels
*/

#ifndef TOOLS_H
    #define TOOLS_H

int is_concerned(ptype_t t);
int fast_atoi(const char *str);
void save_as_png(sfTexture* texture, const char* path);
char *str(const char *str, int i);
#endif /* TOOLS_H */
