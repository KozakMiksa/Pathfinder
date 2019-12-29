#include "path.h"
// Adj[stack_p->next_point]->to, Adj[stack_p->next_point]->weight
t_route *create_route(int point);
t_stack *create_stack(int next, int next_point, int weight);
void mx_stack(t_stack **stack, int next, int weight);
void del_first_stack(t_stack **stack);
void pb_route(t_route **route, int next);

// static void print_list(t_route **adj) {
//         t_route **tmp = adj;
//         while ((*adj) != NULL) {
//             printf("%d", (*adj)->point);
//             (*adj) = (*adj)->next;
//         }
//         adj = tmp;
//         printf("\n%s\n", "=====================");
//     }


void mx_deep_search(t_adj **Adj, int **mxW, char **orig, int size) {
    t_stack *stack_p = NULL;
    // t_Adj *Adj = *Adj;
    t_adj *tmp = NULL;
    // Adj = NULL;
    // mxW = NULL;
    // orig = NULL;
    // size = 2;

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++) {
            stack_p = create_stack(i, i, 0);
            //write(1,"1\n",2);
            while (stack_p != NULL) {
                //write(1,"2\n",2);
                if (stack_p->weight < mxW[i][j]) {
                    
                    // mx_printint(stack_p->next_point);
                    tmp = Adj[stack_p->next_point];
                    if (Adj[stack_p->next_point] == NULL)
                        write(1,"0\n",2);
                    while (Adj[stack_p->next_point] != NULL) {    
                        mx_stack(&stack_p, Adj[stack_p->next_point]->to, Adj[stack_p->next_point]->weight);
                        Adj[stack_p->next_point] = Adj[stack_p->next_point]->next;
                        //mx_printstr("as\n");
                        
                    }
                    //write(1,"3\n",2);
                    Adj[stack_p->next_point] = tmp;
                    del_first_stack(&stack_p);
                    
                      //write(1,"4\n",2);
                }
                else if (stack_p->next_point != j) {
                    //write(1,"5\n",2);
                    del_first_stack(&stack_p);
                }
                else {
                    //write(1,"6\n",2);
                    mx_fill_path(&stack_p->route, mxW, orig);
                    del_first_stack(&stack_p);
                }
            }
        }
}

void pb_route(t_route **route, int next) {
  t_route *r = *route;
  t_route *new_r = create_route(next);
  
  while (r->next != NULL) {
    r = r->next;
  }
  r->next = new_r;
}

void del_first_stack(t_stack **stack) {
  t_stack *Stack = *stack;
  if (Stack->next != NULL) {
   *stack = Stack->next;
   free(Stack);
  }
  else {
   // write(1,"7\n",2);
  free(Stack);
  *stack = NULL;
  }

}

t_route *create_route(int point) {
  t_route *new_r = malloc(sizeof(t_route));
  
  new_r->point = point;
  new_r->next = NULL;
  return new_r;
}

t_stack *create_stack(int next, int next_point, int weight) {
  t_stack *new_s = malloc(sizeof(t_stack));
  new_s->route = create_route(next_point);
  
  new_s->next_point = next;
  new_s->weight = weight;
  new_s->next = NULL;
  return new_s;
}

void mx_stack(t_stack **stack, int next, int weight) {
  t_stack *Stack = *stack;
  t_stack *new_s = create_stack(next, Stack->route->point, Stack->weight + weight);
  t_route *tmp = NULL;
  t_route *tmp_r = NULL;
  
  if (Stack->next != NULL) {
    new_s->next = Stack->next;
    Stack->next = new_s;
  }
  else {
    Stack->next = new_s;
  }
  tmp = new_s->route;
  tmp_r = Stack->route;
  while (tmp_r->next != NULL) {
        tmp_r = tmp_r->next;
    pb_route(&tmp, tmp_r->point);
  }
  pb_route(&tmp, next);
}

