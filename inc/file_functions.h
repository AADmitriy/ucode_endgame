#pragma once

#include <stdbool.h>

void mx_write_into_file(int fd, const char *str);
char *mx_file_to_str(const char *filename);
bool mx_add_to_file(const char *filename, const char *artist, const char *name);
bool mx_remove_from_file(const char *filename, int index);
bool mx_sort_file(const char *filename, const char *option);
bool mx_print_file(const char *filename);

