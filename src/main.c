#include "path.h"

int main(int argc, char *argv[]) {
	char **arr = NULL;
    char **orig = mx_printerror(argc, argv[1], &arr);
    rib_t *list = mx_arr_to_list(arr);
    
    // while (list != NULL) {
    // 	mx_printstr(list->isl1);
    // 	mx_printchar('\n');
    // 	mx_printstr(list->isl2);
    // 	mx_printchar('\n');
    // 	mx_printint(list->dist);
    // 	mx_printchar('\n');
    // 	list = list->next;
    // }
    //system("leaks -q pathfinder");
    return 0;
}
