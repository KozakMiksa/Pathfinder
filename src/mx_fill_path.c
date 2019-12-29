#include "path.h"

void print_path(t_route *test, char **arr);
void print_route(t_route *test, char **arr);


void mx_fill_path(t_route **route, int **mxW, char **orig) {
    print_path(*route, orig);
    print_route(*route, orig);
    // route = NULL;
    // orig = NULL;
    mxW = NULL;
}

void print_path(t_route *test, char **arr) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(arr[test->point]);
    mx_printstr(" -> ");
    while (test->next != NULL)
        test = test->next;
    mx_printstr(arr[test->point]);
    mx_printchar('\n');
}
void print_route(t_route *test, char **arr) {
    mx_printstr("Route: ");
    while (test->next != NULL) {
        mx_printstr(arr[test->point]);
        mx_printstr(" -> ");
        test = test->next;
    }
    mx_printstr(arr[test->point]);
    mx_printchar('\n');
}
// void print_dist(t_route *test) {
//     mx_printstr(“Distance: “);
//     while (test->next != NULL) {
//         mx_printint(test->isl);
//         mx_printstr(" + “);
//         test = test->next;
//     }
//     mx_printint(test->isl);
//     mx_printstr(" = “);
//     mx_printint(20);
//     mx_printchar(‘\n’);
//     mx_printstr(“========================================\n");
// }
