#include "path.h"

void mx_fill_path(char **orig) {
    orig = NULL;
}

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_route {
    int point;
    struct s_route *next;
} t_route;

typedef struct s_stack {
    t_route *route;
    int next_point;
    int weight;
    struct s_stack *next;
} t_stack;

t_route *create_route(int point) {
  t_route *new_r = malloc(sizeof(t_route));
  
  new_r->point = point;
  new_r->next = NULL;
  return new_r;
}

t_stack *create_stack(int next, int next_point, int weight ) {
  t_stack *new_s = malloc(sizeof(t_stack));
  new_s->route = create_route(next_point);
  
  new_s->next_point = next;
  new_s->weight = weight;
  new_s->next = NULL;
  return new_s;
}

void pb_route(t_route **route, int next) {
  t_route *r = *route;
  t_route *new_r = create_route(next);
  
  // // while (r->next != NULL) {
  // //   r = r->next;
  // // }
  r->next = new_r;
}

void to_second(t_stack **stack, int next, int weight) {
  t_stack *Stack = *stack;
  t_stack *new_s = create_stack(next, Stack->route->point, Stack->weight + weight);
  t_route *tmp = NULL;
  
  if (Stack->next != NULL) {
    new_s->next = Stack->next;
    Stack->next = new_s;
  }
  else {
    Stack->next = new_s;
  }
  tmp = new_s->route;
  // while (tmp != NULL) {
    pb_route(&tmp, next);
    // tmp = tmp->next;
  // }
}

int main() {
  t_stack *new_s = create_stack(0, 0, 0);
  to_second(&new_s, 1, 7);
  
  return 0;
}