#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack Stack;

#define MAX_STACK 1000

/**
 * Cria uma pilha genérica
 */
Stack* stack_create(void);

/**
 * Empilha um valor na pilha
 */
void stack_push(Stack* s, void* data);

/**
 * Desempilha um dado passado como argumento da pilha
 * Retorna o dado removido
 */
void* stack_pop(Stack* s, void* data);

/**
 * Informa se a pilha está vazia
 */
bool stack_is_empty(Stack* s);

/**
 * Retorna o dado do topo da pilha sem remover
 */
void* stack_top(Stack* s);

/**
 * Desaloca a pilha
 */
void stack_destroy(Stack** s);

#endif