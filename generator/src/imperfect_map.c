/*
** EPITECH PROJECT, 2021
** dante
** File description:
** imperfect.c
*/

#include "generator.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char **break_wall_imperfect(char **map, int i, int j)
{
    int random;

    if (j % 2 == 0) {
        random = rand();
        if (random % 2 == 0)
            map[i][j - 1] = '*';
        else
            map[i - 1][j] = '*';
    }
    return (map);
}

char **randomise_imperfect(char **map, int w, int h)
{
    for (int i = 2; i < h; i++) {
        for (int j = 2; j < w; j++) {
            map = break_wall_imperfect(map, i, j);
        }
    }
    return (map);
}

char **generate_imperfect(int w, int h)
{
    char **map = malloc(sizeof(char *) * (h + 1));
    map[0] = malloc(sizeof(char) * (w + 2));
    for (int i = 0; i < w; i++)
        map[0][i] = '*';
    map[0][w] = '\0';
    for (int i = 1; i < h; i++) {
        map[i] = malloc(sizeof(char) * (w + 2));
        if (i % 2 == 1)
            map[i] = fill_x(map[i], w);
        else
            map[i] = one_out_of_two(map[i], w);
    }
    map = randomise_imperfect(map, w, h);
    map[h - 1][w - 1] = '*';
    if (h % 2 == 0 && w % 2 == 0)
        map[h - 1][w - 2] = '*';
    printf("%s", map[0]);
    for (int i = 1; i < h; i++)
        printf("\n%s", map[i]);
    return (map);
}
