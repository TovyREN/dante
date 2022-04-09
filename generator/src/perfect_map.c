/*
** EPITECH PROJECT, 2022
** dante
** File description:
** main generator
*/

#include <stdio.h>
#include <stdlib.h>

char **break_wall(char **map, int i, int j)
{
    int random;

    if (map[i][j] == '*') {
        random = rand();
        if (random % 2 == 0)
            map[i][j - 1] = '*';
        else
            map[i - 1][j] = '*';
    }
    return (map);
}

char **randomise(char **map, int w, int h)
{
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            map = break_wall(map, i, j);
        }
    }
    return (map);
}

char *fill_x(char *map, int w)
{
    map[0] = '*';
    for (int i = 1; i < w; i++) {
        map[i] = 'X';
    }
    map[w] = '\0';
    return (map);
}

char *one_out_of_two(char *map, int w)
{
    map[0] = '*';
    for (int i = 1; i < w; i++) {
        if (i % 2 == 1)
            map[i] = 'X';
        else
            map[i] = '*';
    }
    map[w] = '\0';
    return (map);
}

char **create_map(int w, int h)
{
    char **map = malloc(sizeof(char *) * (h + 1));
    map[0] = malloc(sizeof(char) * (w + 1));
    for (int i = 0; i < w; i++)
        map[0][i] = '*';
    map[0][w] = '\0';
    for (int i = 1; i < h; i++) {
        map[i] = malloc(sizeof(char) * (w + 1));
        if (i % 2 == 1)
            map[i] = fill_x(map[i], w);
        else
            map[i] = one_out_of_two(map[i], w);
    }
    map = randomise(map, w, h);
    map[h - 1][w - 1] = '*';
    if (h % 2 == 0 && w % 2 == 0)
        map[h - 1][w - 2] = '*';
    printf("%s", map[0]);
    for (int i = 1; i < h; i++)
        printf("\n%s", map[i]);
    return (map);
}
