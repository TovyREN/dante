/*
** EPITECH PROJECT, 2022
** dante
** File description:
** size function for solver
*/

#include "solver.h"
#include <unistd.h>
#include <sys/stat.h>

int width_of(char *buffer)
{
    int count = 0;

    for (count = 0; buffer[count] != '\n'; count++);
    return count;
}

int heigth_of(char *buffer)
{
    int count = 1;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count += 1;
    }
    return count;
}

int size_of(char const *filepath)
{
    struct stat buf;

    stat(filepath, &buf);
    int size = buf.st_size;
    return size;
}
