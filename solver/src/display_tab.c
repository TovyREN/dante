/*
** EPITECH PROJECT, 2022
** dante
** File description:
** display_tab
*/

#include "solver.h"
#include <stdio.h>

void get_path(map_t *map)
{
    int y = 0;
    int x = 0;

    while (x != map->width && y != map->height) {
        if (map->map[y][x] == 'R')
            map->map[y][x++] = 'o';
        if (map->map[y][x] == 'D')
            map->map[y++][x] = 'o';
        if (map->map[y][x] == 'L')
            map->map[y][x--] = 'o';
        if (map->map[y][x] == 'U')
            map->map[y--][x] = 'o';
        if (map->map[y][x] == 'o')
            break;
    }
}

void clean_tab(map_t *map)
{
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            if (map->map[y][x] == 'R')
                map->map[y][x] = '*';
            if (map->map[y][x] == 'D')
                map->map[y][x] = '*';
            if (map->map[y][x] == 'L')
                map->map[y][x] = '*';
            if (map->map[y][x] == 'U')
                map->map[y][x] = '*';
        }
    }
}

void display_tab(map_t *map)
{
    get_path(map);
    clean_tab(map);
    printf("%s", map->map[0]);
    for (int y = 1; y < map->height; y++)
        printf("\n%s", map->map[y]);
}
