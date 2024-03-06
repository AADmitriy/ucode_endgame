#pragma once

#include "stdbool.h"

int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
int mx_atoi(const char *s);
bool mx_isspace(char c);
bool mx_isdigit(char c);
char mx_tolower(char c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strnew(int size);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_buffer_to_string(char buffer[], int bytes_to_read);

