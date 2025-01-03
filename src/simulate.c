#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <omp.h>
#include <math.h>

#include "define.h"
#include "simulate.h"

void reset(node_inf *node, cell_inf *cell)
{
    for (int h = 0; h < node_num; h++)
    {
        node[h].ready = 0;
        node[h].x = length * cell_num * 10;
        node[h].apper_coordinate = node[h].x;
        node[h].stay_cell_num = 1000;
        node[h].service_server_num = 1000;
        node[h].start_time = 0;
        node[h].holding_time = 0;
        node[h].block_flag = 0;
        node[h].service_done = 0;
    }

    for (int h = 0; h < cell_num; h++)
    {
        cell[h].start_cell_coordinate = length * h;
        cell[h].end_cell_coordinate = length * (h + 1);
        for (int i = 0; i < server_num; i++)
        {
            cell[h].server[i].usingflag = 0;
        }
    }
}

void set_poisson_distribution(node_inf *node, cell_inf *cell)
{
    double r = (double)rand() / (RAND_MAX + 1.0);
    node[0].start_time = -(1 / lambda) * log(r);
    r = (double)rand() / (RAND_MAX + 1.0);
    node[0].holding_time = -(1 / mu) * log(r);
    node[0].apper_coordinate = ((double)rand() / RAND_MAX) * length * cell_num;
    node[0].x = node[0].apper_coordinate;

    for (int h = 1; h < node_num; h++)
    {
        r = (double)rand() / (RAND_MAX + 1.0);
        node[h].start_time = node[h - 1].start_time + (-(1 / lambda) * log(r));
        r = (double)rand() / (RAND_MAX + 1.0);
        node[h].holding_time = -(1 / mu) * log(r);
        node[h].apper_coordinate = ((double)rand() / RAND_MAX) * length * cell_num;
        node[h].x = node[h].apper_coordinate;
        node[h].stay_cell_num = (int)node[h].apper_coordinate / 500;
    }

    for (int h = 0; h < node_num; h++)
    {
        node[h].stay_cell_num = search_cell_number(node, cell, h);
        // printf("hello");
    }
}

int search_cell_number(node_inf *node, cell_inf *cell, int num)
{
    for (int i = 0; i < cell_num; i++)
    {
        if (cell[i].start_cell_coordinate < node[num].x && node[num].x < cell[i].end_cell_coordinate)
        {
            return i;
        }
    }
}

void simulate(node_inf *node, cell_inf *cell, double time)
{
    for (int h = 0; h < node_num; h++)
    {
        if (node[h].ready == 1)
        {
            node[h].holding_time -= dt;
            if (node[h].holding_time <= 0)
            {
                node[h].ready = 0;
                cell[node[h].stay_cell_num].server[node[h].service_server_num].usingflag = 0;
            }
            move_node(node, cell, h);
        }
    }

    for (int h = 0; h < node_num; h++)
    {
        if (node[h].start_time - time <= 0.001 && node[h].service_done == 0)
        {
            int not_using_server_num = -1;
            for (int i = 0; i < server_num; i++)
            {
                if (cell[node[h].stay_cell_num].server[i].usingflag == 0)
                {
                    not_using_server_num = i;
                    break; // 最初に見つけた空いているサーバーでループを終了
                }
            }

            if (not_using_server_num == -1)
            {
                node[h].block_flag = 1;
                node[h].service_done = 1;
            }
            else
            {
                node[h].ready = 1;
                node[h].service_server_num = not_using_server_num;
                cell[node[h].stay_cell_num].server[not_using_server_num].usingflag = 1;
                node[h].service_done = 1;
            }
        }
    }
}

void move_node(node_inf *node, cell_inf *cell, int num)
{
    if (node[num].ready == 0)
    {
        return;
    }

    node[num].x += dt * v;
    if (node[num].x > cell[node[num].stay_cell_num].end_cell_coordinate)
    {
        if (node[num].stay_cell_num == cell_num - 1)
        {
            int add_coordinate = node[num].x - cell[node[num].stay_cell_num].end_cell_coordinate;
            node[num].stay_cell_num = 0;
            node[num].x = 0;
            node[num].x += add_coordinate;
        }
        else
        {
            node[num].stay_cell_num++;
        }
        int not_using_server_num = -1;
        for (int i = 0; i < server_num; i++)
        {
            if (cell[node[num].stay_cell_num].server[i].usingflag == 0)
            {
                not_using_server_num = i;
                break; // 最初に見つけた空いているサーバーでループを終了
            }
        }

        if (not_using_server_num == -1)
        {
            node[num].block_flag = 1;
        }
        else
        {
            node[num].service_server_num = not_using_server_num;
            cell[node[num].stay_cell_num].server[not_using_server_num].usingflag = 1;
        }
    }
}

void plot(node_inf *node)
{
    char *data_file;
    FILE *fp;

    data_file = "./result/Blocking_probability.txt";
    fp = fopen(data_file, "a");
    int blocking_node_counter = 0, service_done_flag = 0;
    for (int h = 0; h < node_num; h++)
    {
        if (node[h].start_time > check_start_time)
        {
            if (node[h].block_flag == 1)
            {
                blocking_node_counter++;
            }
            if (node[h].service_done == 1)
            {
                service_done_flag++;
            }
        }
    }

    double Ps = 0.0, Ps_denominator = 0.0, Ps_numerator;

    for (int h = 0; h <= server_num; h++)
    {
        Ps_denominator += (pow((lambda / mu), (double)h)) / (double)kaijo(h);
    }

    Ps_numerator = pow((lambda / mu), (double)server_num) / (double)kaijo(server_num);

    Ps = Ps_numerator / Ps_denominator;

    // printf("Ps = %lf\n", Ps);

    // printf("block_count = %d\n", blocking_node_counter);
    // printf("service_count = %d\n", service_done_flag);
    fprintf(fp, "%lf\n", (double)((double)blocking_node_counter / (double)service_done_flag));
    fclose(fp);
}

int kaijo(int num)
{
    int count = num;

    if (num == 0)
    {
        return 1;
    }

    int result = 1;
    while (count > 0)
    {
        result *= count;
        count--;
    }

    return result;
}