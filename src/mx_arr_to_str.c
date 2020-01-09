#include "path.h"

char *mx_arr_to_str(char **arr, char *str_new) {
    char *str = mx_strnew(mx_strlen(str_new));
    int s = 0;

    mx_strdel(&str_new);
    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != ',';) {
            str[s++] = arr[i][j++];
            if (mx_isalpha(arr[i][j]) != 1) {
                str[s++] = ',';
                if (arr[i][j] != ',')
                    j++;
            }
        }
    }
    return str;
}
