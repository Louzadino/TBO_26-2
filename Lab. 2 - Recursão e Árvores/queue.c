#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue {
    void* data[MAX_QUEUE];
    int init; 
    int last;    
    int n;      // Número de elementos na fila
};

Queue* queue_create(void) {
    Queue* f = (Queue*) malloc(sizeof(Queue));
    if (f != NULL) {
        f->init = 0;
        f->last = 0;
        f->n = 0;
    }
    return f;
}

void queue_destroy(Queue** f_ptr) {
    if (f_ptr != NULL && *f_ptr != NULL) {
        free(*f_ptr);
        *f_ptr = NULL;
    }
}

bool queue_is_empty(Queue* f) {
    return f->n == 0;
}

bool queue_is_full(Queue* f) {
    return f->n == MAX_QUEUE;
}

void enqueue(Queue* f, void* data) {
    if (queue_is_full(f)) {
        printf("Erro: Fila cheia\n");
        exit(EXIT_FAILURE);
    }
    
    f->data[f->last] = data;
    f->last = (f->last + 1); // Avança o fim (circular)
    f->n++;
}

void* dequeue(Queue* f) {
    if (queue_is_full(f)) {
        printf("Erro: Fila vazia\n");
        exit(EXIT_FAILURE);
    }

    void* data = f->data[f->last];
    f->init = (f->init + 1); // Avança o início (circular)
    f->n--;
    return data;
}