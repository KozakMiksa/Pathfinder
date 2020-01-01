#include "path.h"

int main(int argc, char *argv[]) {
	int i = 0;
	char **arr = NULL;
    char **orig = mx_printerror(argc, argv[1], &arr);
    t_rib *list = mx_arr_to_list(arr, i);
    int size = mx_atoi(arr[0]);

    mx_del_strarr(&arr);
    mx_pathfinder(list, orig, size);
    

    // system("leaks -q pathfinder");
    return 0;
}
