#include "path.h"

int main(int argc, char *argv[]) {
	char **arr = NULL;
    char **orig = mx_printerror(argc, argv[1], &arr);
    rib_t *list = mx_arr_to_list(arr);
    
    mx_pathfinder(list, orig, mx_atoi(arr[0]));
    
    // system("leaks -q pathfinder");
    return 0;
}
