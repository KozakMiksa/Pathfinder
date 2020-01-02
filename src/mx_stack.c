#include "path.h"

static t_route *create_route(int point);
static t_stack *create_stack(int next, int next_point, int weight);
static void pb_route(t_route **route, int next);

void mx_stack(t_stack **stack, int next, int weight) {
    t_stack *Stack = *stack;
    t_stack *new_s = create_stack(next, Stack->route->point,
                                  Stack->weight + weight);
    t_route *tmp = NULL;
    t_route *tmp_r = NULL;
  
    if (Stack->next != NULL) {
        new_s->next = Stack->next;
        Stack->next = new_s;
    }
    else
        Stack->next = new_s;
    tmp = new_s->route;
    tmp_r = Stack->route;
    while (tmp_r->next != NULL) {
        tmp_r = tmp_r->next;
        pb_route(&tmp, tmp_r->point);
    }
    pb_route(&tmp, next);
}

static t_route *create_route(int point) {
    t_route *new_r = malloc(sizeof(t_route));
  
    new_r->point = point;
    new_r->next = NULL;
    return new_r;
}

static t_stack *create_stack(int next, int next_point, int weight) {
    t_stack *new_s = malloc(sizeof(t_stack));
    new_s->route = create_route(next_point);
  
    new_s->next_point = next;
    new_s->weight = weight;
    new_s->next = NULL;
    return new_s;
}

static void pb_route(t_route **route, int next) {
    t_route *r = *route;
    t_route *new_r = create_route(next);

    while (r->next != NULL)
        r = r->next;
    r->next = new_r;
}
