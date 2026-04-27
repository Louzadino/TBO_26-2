#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"

int main() {

    // Criação da árvore
    BST* bst = create_bst();

    int N;
    scanf("%d", &N);

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        int new_key = rand();
        Node* new_node = create_node(new_key);
        insert_bst(bst, new_node);
    }
    
    /*
    // Processamento das operações
    char operation;
    int exit = 0;
    while (1) {
        scanf("%c", &operation);

        switch (operation)
        {
        // Caso seja um inserção
        case 'I':
            int new_key;
            scanf(" %d", &new_key);
            Node* new_node = create_node(new_key);
            insert_bst(bst, new_node);
            printf("Nó de chave %d inserido\n", new_key);
            break;
        
        case 'X':
            exit = 1;
            break;

        default:
            break;
        }

        if (exit == 1) {
            printf("Fim do processamento\n");
            break;
        }
    }
        */
    
    destroy_bst(bst);

    return 0;
}
