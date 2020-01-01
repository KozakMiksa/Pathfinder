#include "path.h"

static void print_path(t_route *test, char **arr);
static void print_route(t_route *test, char **arr);
static void print_dist(t_route *test, int **mxW);


void mx_fill_path(t_route **route, int **mxW, char **orig) {
    t_route *r = *route;

    print_path(*route, orig);
    print_route(*route, orig);
    print_dist(r, mxW);
}



static void print_path(t_route *test, char **arr) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(arr[test->point]);
    mx_printstr(" -> ");
    while (test->next != NULL)
        test = test->next;
    mx_printstr(arr[test->point]);
    mx_printchar('\n');
}
static void print_route(t_route *test, char **arr) {
    mx_printstr("Route: ");
    while (test->next != NULL) {
        mx_printstr(arr[test->point]);
        mx_printstr(" -> ");
        test = test->next;
    }
    mx_printstr(arr[test->point]);
    mx_printchar('\n');
}
static void print_dist(t_route *test, int **mxW) {
    t_route *t = test;

    mx_printstr("Distance: ");
    if (test->next->next != NULL) {
        while (test->next->next != NULL) {
            mx_printint(mxW[test->point][test->next->point]);
            mx_printstr(" + ");
            test = test->next;
        }
        mx_printint(mxW[test->point][test->next->point]);
        mx_printstr(" = ");
    }
    mx_printint(mxW[t->point][test->next->point]);
    mx_printchar('\n');
    mx_printstr("========================================\n");
}
