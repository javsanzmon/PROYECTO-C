#include "input/input_usr.h"

//tengo que hacer un get_string y get_num

struct process* create_process(char *user, int p, int c) {
    // Reservamos memoria dinamica
    struct process *create_process = malloc(sizeof(struct process));

    // if por si hay fallo de malloc
    if (create_process == NULL) {
        return NULL;
    }

    // Asignamos nombre prioridad y tiempo de ejecucion

    create_process->data.user = user;
    create_process->data.p = p;
    create_process->data.C = c;

    create_process->data.state = READY;

    // por ahora dejamos el PID en 0
    create_process->pid = 0;

    return create_process;
}