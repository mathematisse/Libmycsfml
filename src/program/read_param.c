/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "program.h"

void load_hyperparams(prog_param_t *params, const char* path)
{
    char* line = NULL;
    size_t len = 0;
    FILE* file = NULL;

    file = fopen(path, "r");
    if (file == NULL) {
        printf("File '%s' could not be opened\n", path);
    }
    while (getline(&line, &len, file) != -1) {
        if (strstr(line, "WIDTH") != NULL) {
            params->width = atoi(strstr(line, "=") + 2);
        } else if (strstr(line, "HEIGHT") != NULL) {
            params->height = atoi(strstr(line, "=") + 2);
        } else if (strstr(line, "FULLSCREEN") != NULL) {
            params->fullscreen = atoi(strstr(line, "=") + 2);
        } else if (strstr(line, "SCALE") != NULL) {
            params->scale = atof(strstr(line, "=") + 2);
        } else if (strstr(line, "MUSIC_VOLUME") != NULL) {
            params->music_volume = atof(strstr(line, "=") + 2);
        } else if (strstr(line, "SOUND_VOLUME") != NULL) {
            params->sound_volume = atof(strstr(line, "=") + 2);
        }  else if (strstr(line, "USER") != NULL) {
            params->user = strdup(strstr(line, "=") + 2);
        }
    }
    fclose(file);
}

void load_userparams(user_t *params, const char* path)
{
    char* line = NULL;
    size_t len = 0;
    FILE* file = NULL;

    file = fopen(path, "r");
    if (file == NULL) {
        printf("File '%s' could not be opened\n", path);
    }
    while (getline(&line, &len, file) != -1) {
        if (strstr(line, "CREDIT") != NULL) {
            params->credit = atoi(strstr(line, "=") + 2);
        } else if (strstr(line, "SCORE") != NULL) {
            params->score = atoi(strstr(line, "=") + 2);
        } else if (strstr(line, "LEVEL") != NULL) {
            params->level = atoi(strstr(line, "=") + 2);
        } else if (strstr(line, "WALK_SPEED") != NULL) {
            params->walk_speed = atof(strstr(line, "=") + 2);
        } else if (strstr(line, "RELOAD_SPEED") != NULL) {
            params->reload_speed = atof(strstr(line, "=") + 2);
        } else if (strstr(line, "LIFE") != NULL) {
            params->life = atof(strstr(line, "=") + 2);
        } else {
            break;
        }
    }
    while (getline(&line, &len, file) != -1) {
        if (strstr(line, "INVENTORY") != NULL) {
            params->inventory[atoi(strstr(line, "[") + 1)]
            [atoi(strstr(line, ",") + 2)]
            [atoi(strstr(line, "]") + 1)] = atoi(strstr(line, "=") + 2);
        }
    }
    fclose(file);
}

void save_hyperparams(prog_param_t *params, const char* path)
{
    FILE* file = NULL;

    file = fopen(path, "w");
    if (file == NULL) {
        printf("File '%s' could not be opened\n", path);
    }
    fprintf(file, "WIDTH = %d\n", params->width);
    fprintf(file, "HEIGHT = %d\n", params->height);
    fprintf(file, "FULLSCREEN = %d\n", params->fullscreen);
    fprintf(file, "SCALE = %f\n", params->scale);
    fprintf(file, "MUSIC_VOLUME = %f\n", params->music_volume);
    fprintf(file, "SOUND_VOLUME = %f\n", params->sound_volume);
    fprintf(file, "USER = %s\n", params->user);
    fclose(file);
}