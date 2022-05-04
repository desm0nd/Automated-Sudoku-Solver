#ifndef SOLVER_H
#define SOLVER_H
#include <stdbool.h>
#include <stdint.h>
#include "graph.h"


bool index_in_group(int *group, int size, int index);
void link_vertex_with_group(int *group, int size, int index, struct vertex **vertices);
void link_three_groups(struct vertex **vertices);
void link_cols_and_rows(struct vertex **vertices);
struct graph *load_initial(char* arr);
int graph_main(char* arr);
#endif