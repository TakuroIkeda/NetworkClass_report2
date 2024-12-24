#ifndef DEFINE_H
#define DEFINE_H

#define server_num 5
#define TIME 10000
#define lambda 0.05
#define node_num 1030
#define mu 0.05
#define dt 0.1
#define seed 1101
#define roop_count 10
#define length 500
#define cell_num 10
#define v 10

typedef struct
{
    int usingflag;
} server_inf;

typedef struct
{
    double start_cell_coordinate;
    double end_cell_coordinate;
    server_inf server[server_num];
} cell_inf;

typedef struct
{
    int ready;
    double x;
    double apper_coordinate;
    int stay_cell_num;
    int service_server_num;
    double start_time;
    double holding_time;
    int block_flag;
    int service_done;
} node_inf;

#endif