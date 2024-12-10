#ifndef SIMULATE_H
#define SIMULATE_H

#include "define.h"

void reset(node_inf *node, cell_inf *cell);

void set_poisson_distribution(node_inf *node, cell_inf *cell);

int search_cell_number(node_inf *node, cell_inf *cell, int num);

void simulate(node_inf *node, cell_inf *cell, double time);

void move_node(node_inf *node, cell_inf *cell, int num);

void plot(node_inf *node);

int kaijo(int num);

#endif