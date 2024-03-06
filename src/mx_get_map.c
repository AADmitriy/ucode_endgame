#include <stdlib.h>

#include "file_functions.h"
#include "output_functions.h"
#include "string_functions.h"

int count_newlines(const char* str) {
    int count = 0;

    while (*str != '\0') {
        if (*str == '\n') {
            count++;
        }
        str++;
    }

    return count;
}

int count_line_length(const char* str) {
    int count = 0;

    while (*str != '\0' && *str != '\n') {
        count++;
        str++;
    }

    return count;
}

// caution error prone!
int **mx_get_map(const char *filename, int *height, int *width) {
    char *map_str = mx_file_to_str(filename);

    int map_height = count_newlines(map_str);
    int map_width = count_line_length(map_str);

    int **map = (int**)malloc(sizeof(int*) * map_height);
    int *map_line;

    for (int row = 0; row < map_height; row++) {
        map_line = (int*)malloc(sizeof(int) * map_width);

        for (int col = 0; col < map_width; col++) {
            map_line[col] = map_str[row * (map_width + 1) + col] - '0';
        }

        map[row] = map_line;
    }

    free(map_str);

    *height = map_height;
    *width = map_width;

    return map;
}

