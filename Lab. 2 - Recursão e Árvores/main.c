#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

void visit(int key) {
    printf("%d\n", key);
    // FAZ NADA
}

int main() {

    long N = 5;
    
    // Configura o gerador aleatório (Exercício 2)
    srand(time(NULL)); 

    printf("Criando arvore com N = %ld...\n", N);
    BST* bst = create_bst();
    for (long i = 0; i < N; i++) {
        Node* new_node = create_node(rand());
        insert_bst(bst, new_node);
    }
    printf("arvore criada. Altura: %d\n", bst_height(bst_root(bst)));
    printf("Iniciando medicoes de tempo...\n\n");

    clock_t start, end;
    double tempo_cpu;

    // Medindo Pre-order
    start = clock();
    rec_pre_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Pre-order (Recursivo):   %f segundos\n", tempo_cpu);

    start = clock();
    it_pre_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Pre-order (Nao-Recursivo): %f segundos\n\n", tempo_cpu);

    // Medindo In-order
    start = clock();
    rec_in_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("In-order (Recursivo):    %f segundos\n", tempo_cpu);
    
    start = clock();
    it_in_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("In-order (Nao-Recursivo):  %f segundos\n\n", tempo_cpu);
    

    // Medindo Post-order
    start = clock();
    rec_post_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Post-order (Recursivo):  %f segundos\n", tempo_cpu);

    start = clock();
    it_post_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Post-order (Nao-Recursivo):%f segundos\n\n", tempo_cpu);

    // Medindo Level-order
    start = clock();
    it_level_order_traversal(bst_root(bst), visit);
    end = clock();
    tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Level-order (Iterativo):  %f segundos\n", tempo_cpu);

    destroy_bst(bst);
    return 0;
}
