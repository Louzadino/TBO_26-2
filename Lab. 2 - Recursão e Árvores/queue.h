#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

#define MAX_QUEUE 1000

typedef struct Queue Queue;

/**
 * Cria e aloca a estrutura fila
 */
Queue* queue_create(void);

/**
 * Destroi e libera a estrutura fila
 */
void queue_destroy(Queue** f_ptr);

/**
 * Informa se a fila está vazia
 */
bool queue_is_empty(Queue* f);

/**
 * Informa se a fila está cheia
 */
bool queue_is_full(Queue* f);

/**
 * Enfileira um dado na fila
 */
void enqueue(Queue* f, void* data);

/**
 * Desenfileira um dado da fila.
 * O dado desenfileirado é retornado
 */
void* dequeue(Queue* f);

#endif