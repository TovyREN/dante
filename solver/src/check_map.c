/*
** EPITECH PROJECT, 2022
** dante
** File description:
** check map
*/

#include "solver.h"
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char **copy_map_from_buff(char *buffer)
{
    int count = 0;
    int height = heigth_of(buffer);
    int width = width_of(buffer);
    char **map = malloc(sizeof(char *) * (height));
    int y = 0;

    while (y < height) {
        map[y] = malloc(sizeof(char) * (width + 1));
        for (int x = 0; x < width; x++) {
            map[y][x] = buffer[count];
            count += 1;
            map[y][x + 1] = '\0';
        }
        count += 1;
        y++;
    }
    return map;
}

void init_map(char *buffer, map_t *map)
{
    map->tp_pos = malloc(sizeof(pos_t) * strlen(buffer));
    map->map = copy_map_from_buff(buffer);
    map->tp_pos[0] = (pos_t){0, 0};
    map->count_tp = 1;
    map->width = width_of(buffer);
    map->height = heigth_of(buffer);
    map->pos_x = 0;
    map->pos_y = 0;
}

int is_map(char **map, int y)
{
    for (int x = 0; map[y][x] != '\0'; x++) {
        if (map[y][x] != '*' && map[y][x] != 'X') {
            return 1;
        }
    }
    return 0;
}

int check_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        if (!is_map(map, y))
            return 1;
    }
    return 0;
}

char *read_map(char *filepath)
{
    int size = size_of(filepath);
    char *buffer = malloc(sizeof(char) * (size + 1));
    int fd = open(filepath, O_RDONLY);

    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}
