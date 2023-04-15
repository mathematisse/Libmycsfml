/*
** PERSONNAL PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <unistd.h>
#include "program.h"
#include "theme.h"

panel_t *demopanel(void);

int show_help(void)
{
    write(1, HELP_TEXT, sizeof(HELP_TEXT));
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            return show_help();
        return 84;
    }
    return execute_program(demopanel);
}
