#include "path.h"

static int arrlen(char **arr);

char **mx_deldub(char **arr1) {
    char **arr2 = malloc((arrlen(arr1) + 1) * sizeof(char *));
    int c = 1;
    int n = 0;
    int j = 0;

    arr2[0] = mx_strnew(mx_strlen(arr1[0]));
    for (n = 0; n < mx_strlen(arr1[0]); n++)
        arr2[0][n] = arr1[0][n];
    for (int i = 1; arr1[i] != NULL; i++) {
        j = 0;
        for (; mx_strcmp(arr1[i], arr2[j]) != 0 && j < c - 1; j++);
        if (j == c - 1 && mx_strcmp(arr1[i], arr2[j]) != 0) {
            arr2[c] = mx_strnew(mx_strlen(arr1[i]));
            for (n = 0; n < mx_strlen(arr1[i]); n++)
                arr2[c][n] = arr1[i][n];
            c++;
        }
    }
    arr2[c] = NULL;
    return arr2;
}

static int arrlen(char **arr) {
    int count = 0;
    
    while(arr[count] != NULL)
        count++;
    return count;
}
