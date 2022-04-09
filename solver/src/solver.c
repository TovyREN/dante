/*
** EPITECH PROJECT, 2022
** dante
** File description:
** solver backtracking algorith
*/

#include "solver.h"
#include <stdio.h>

int nb_of_path(map_t *map, int x, int y)
{
    int count = 0;

    if (x + 1 < map->width && map->map[y][x + 1] == '*')
        count++;
    if (y > 0 && map->map[y - 1][x] == '*')
        count++;
    if (y + 1 < map->height && map->map[y + 1][x] == '*')
        count++;
    if (x > 0 && map->map[y][x - 1] == '*')
        count++;
    return count;
}

void move(map_t *map, int x, int y)
{
    if (x + 1 < map->width && map->map[y][x + 1] == '*') {
        map->map[y][x] = 'R';
        map->pos_x += 1;
        return;
    }
    if (y + 1 < map->height && map->map[y + 1][x] == '*') {
        map->map[y][x] = 'D';
        map->pos_y += 1;
        return;
    }
    if (x > 0 && map->map[y][x - 1] == '*') {
        map->map[y][x] = 'L';
        map->pos_x -= 1;
        return;
    }
    if (y > 0 && map->map[y - 1][x] == '*') {
        map->map[y][x] = 'U';
        map->pos_y -= 1;
        return;
    }
}

void do_backtracking(map_t *map)
{
    int posibilities = 0;

    while (map->map[map->height - 1][map->width - 1] == '*') {
        posibilities = nb_of_path(map, map->pos_x, map->pos_y);
        while (posibilities > 1) {
            map->tp_pos[map->count_tp] = (pos_t){map->pos_x, map->pos_y};
            map->count_tp++;
            posibilities--;
        }
        if (posibilities == 0 && map->count_tp > 0) {
            map->count_tp--;
            map->map[map->pos_y][map->pos_x] = 'R';
            map->pos_x = map->tp_pos[map->count_tp].x;
            map->pos_y = map->tp_pos[map->count_tp].y;
        }
        move(map, map->pos_x, map->pos_y);
        if (map->pos_x == map->width - 1 && map->pos_y == map->height - 1)
            map->map[map->pos_y][map->pos_x] = 'o';
    }
    display_tab(map);
}
