#ifndef SIMULATE_H
#define SIMULATE_H

#include "define.h"

void reset(node_inf *node, cell_inf *cell);

void set_poisson_distribution(node_inf *node);

void simulate(node_inf *node, cell_inf *cell, double time);

void plot(node_inf *node);

int kaijo(int num);

#endif