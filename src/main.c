#include "path.h"

int main(int argc, char *argv[]) {
    int i = 0;
    char **arr = NULL;
    char **orig = mx_printerror(argc, argv[1], &arr);
    int size = mx_atoi(arr[0]);
    t_rib *list = mx_arr_to_list(arr, i);

    mx_pathfinder(list, orig, size);
    return 0;
}
