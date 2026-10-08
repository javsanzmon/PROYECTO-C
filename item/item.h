// 1. Add a new process to the schedule
#ifndef ITEM_H
#define ITEM_H


enum state {READY, RUNNING, STOPPED, TERMINATED};

// Creo una estructura que pida los datos necesarios
struct data {
    char *user;
    int p;
    int C;
    enum state state;
};


// Creo otra estructura añadiendo la anterior para poder obviar el ID hasta el final.
struct process {
    int pid;
    struct data data;
};







#endif