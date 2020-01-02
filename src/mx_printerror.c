#include "path.h"

static void error_1_2_3(int num, char *f);
static void printerror_5(int i);
static void error_4_5(char **arr);
static char *arr_to_str(char **arr, char *str_new);


char **mx_printerror(int argc, char *argv, char ***arr) {
    error_1_2_3(argc, argv);
    char *str = mx_file_to_str(argv);
    *arr = mx_strsplit(str, '\n');
    error_4_5(*arr);
    int island_size = mx_atoi(*arr[0]);
    str = arr_to_str(*arr, str);
    char **arr_n = mx_strsplit(str, ',');
    mx_strdel(&str);
    char **err6 = mx_deldub(arr_n);
    mx_del_strarr(&arr_n);
    int i = 0;
    for(; err6[i] != NULL; i++);
    if (i != island_size) {
        write(2, "error: invalid number of islands\n", 33);
        exit(0);
    }
    return err6;
}

static void error_1_2_3(int num, char *f) {
    if (num != 2) {
        write(2,"usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }
    int fd = open(f, O_RDONLY);
    if (0 > fd) {
        char *ss = mx_strjoin("error: file ", f);
        char *s = mx_strjoin(ss, " does not exist\n");
        close(fd);
        write(2, s, mx_strlen(s));
        exit(0);
    }
    char buf;
    int c = read(fd, &buf, 1);
    if (c <= 0) {
        char *s = mx_strjoin(mx_strjoin("error: file ", f), " is empty\n");
        close(fd);
        write(2, s, mx_strlen(s));
        exit(0);
    }
}

static void printerror_5(int i) {
    char *s = mx_strjoin("error: line ", mx_itoa(i + 1));
    char *ss = mx_strjoin(s, " isn't valid\n");
    write(2, ss, mx_strlen(ss));
    exit(0);
}

static void error_4_5(char **arr) {
    for (int i = 0; arr[0][i] != '\0'; i++) {
        if (mx_isdigit(arr[0][i]) == 0) {
            write(2, "error: line 1 isn't valid\n", 26);
            exit(0);
        }
    }
    for (int i = 1; arr[i] != NULL; i++) {
        int j = 0;
        for (; arr[i][j] != '-'; j++)
            if (mx_isalpha(arr[i][j]) == 0)
                printerror_5(i);
        j++;
        for (; arr[i][j] != ','; j++)
            if (mx_isalpha(arr[i][j]) == 0)
                printerror_5(i);
        j++;
        for (; arr[i][j] != '\0'; j++)
            if (mx_isdigit(arr[i][j]) == 0)
                printerror_5(i);
    }   
}

static char *arr_to_str(char **arr, char *str_new) {
    char *str = mx_strnew(mx_strlen(str_new));
    mx_strdel(&str_new);
    int s = 0;
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
