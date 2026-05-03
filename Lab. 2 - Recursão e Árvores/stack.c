#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct Stack
{
    void* data[MAX_STACK]; // vetor génerico
    int top; // índice do topo da pilha
};


Stack* stack_create(void) {
    Stack* s = (Stack*) malloc(sizeof(Stack));

    if (!s) {
        printf("FALHA ao alocar pilha\n");
        return NULL;
    }


    s->top = -1; // Indica pilha vazia

    return s;
}

void stack_push(Stack* s, void* data) {
    if (s && data) {
        if (s->top >= MAX_STACK - 1) {
            printf("ESTOURO DA PILHA\n");
            return;
        }

        s->top++;
        s->data[s->top] = data;
    }
}

void* stack_pop(Stack* s) {
    if (s) {
        if (s->top == -1) {
            printf("PILHA VAZIA\n");
            return NULL;
        }

        void* data_return = s->data[s->top];
        s->top--;
        return data_return;
    }
    return NULL;
}

bool stack_is_empty(Stack* s) {
    if (s) return s->top == -1;

    return true;
}

void* stack_top(Stack* s) {
    if (s && s->top != -1) return s->data[s->top];

    return NULL;
}

void stack_destroy(Stack** s_ptr) {
    if (s_ptr != NULL && *s_ptr != NULL) {
        free(*s_ptr);
        *s_ptr = NULL;
    }
}
