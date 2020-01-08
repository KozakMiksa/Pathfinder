#include "libmx.h"

static int strlen_mod(const char *s, char c);

char **mx_strsplit(const char *s, char c) {
    int size = 0;
    char **arr = NULL;

    if (s == NULL)
        return NULL;
    size = mx_count_words(s, c);
    arr = malloc((size + 1) * sizeof(char *));
    for (int i = 0; i < size; i++) {
        while (*s == c && *s != '\0')
            s++;
        arr[i] = mx_strnew(strlen_mod(s, c));
        for(int j = 0; *s != c && *s != '\0'; j++) {
            arr[i][j] = *s;
            s++;
        }
    }
    arr[size] = NULL;
    return arr;
}

static int strlen_mod(const char *s, char c) {
    int count = 0;

    while(*s != c && *s != '\0') {
        count++;
        s++;
    }
    return count;
}
