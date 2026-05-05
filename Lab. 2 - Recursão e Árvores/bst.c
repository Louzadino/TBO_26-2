#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int key;
    Node* parent;
    Node* right_node;
    Node* left_node;
};

struct BST
{
    Node* root;
    int size;
};

Node* create_node(int key) {

    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("ERRO: falha ao alocar novo nó");
        return NULL;
    }

    new_node->key = key;
    new_node->parent = NULL;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

void print_node(Node* n) {
    
    printf("Chave: %d\n", n->key);
    printf("Filho esquerda:\n");
    if (!n->left_node) printf("NULL\n");
    else printf("EXISTE\n");

    printf("Filho direita:\n");
    if (!n->right_node) printf("NULL\n");
    else printf("EXISTE\n");
}

// Para desalocar a árvore inteira
void destroy_node(Node* n) {

    if (n) {
        destroy_node(n->left_node);
        destroy_node(n->right_node);
        free(n);
    }
}

BST* create_bst() {

    BST* bst = (BST*) malloc(sizeof(BST));

    if (bst == NULL) {
        printf("ERRO: falha ao alocar a árvore");
        return NULL;
    }

    bst->root = NULL;
    bst->size = 0;

    return bst;
}

void insert_bst(BST* bst, Node* node_z) {

    Node* node_y = NULL;
    Node* node_x = bst->root;

    while (node_x != NULL) {
        node_y = node_x;
        if (node_z->key < node_x->key) {
            node_x = node_x->left_node;
        } else {
            node_x = node_x->right_node;
        }
    }

    node_z->parent = node_y;
    if (node_y == NULL) {
        bst->root = node_z;
    } else if (node_z->key < node_y->key) {
        node_y->left_node = node_z;
    } else {
        node_y->right_node = node_z;
    }
}

Node* bst_root(BST* bst) {
    return bst->root;
}

int bst_height(Node* n) {

    if (n == NULL) return -1;

    int height_left = bst_height(n->left_node);
    int height_right = bst_height(n->right_node);

    // Usar a logica de que a altura de 1 no é a altura do seu filho mais alto + 1

    if (height_left > height_right) {
        return 1 + height_left;
    } else {
        return 1 + height_right;
    }
}

void destroy_bst(BST* bst) {

    if (bst) {
        destroy_node(bst->root);
        free(bst);
    }
}

void rec_pre_order_traversal(Node* root, visit_func v_func) {

    if (root == NULL) return;
    
    // Visitar nó
    v_func(root->key);
    
    // Visitar sub arvore da esquerda
    rec_pre_order_traversal(root->left_node, v_func);

    // Visitar sub arvore da direite
    rec_pre_order_traversal(root->right_node, v_func);
}

void rec_in_order_traversal(Node* root, visit_func v_func) {

    if (root == NULL) return;

    // Visitar sub arvore da esquerda
    rec_in_order_traversal(root->left_node, v_func);

    // Visitar nó
    v_func(root->key);

    // Visitar sub arvore da direite
    rec_in_order_traversal(root->right_node, v_func);
}

void rec_post_order_traversal(Node* root, visit_func v_func) {

    if (root == NULL) return;

    // Visitar sub arvore da esquerda
    rec_post_order_traversal(root->left_node, v_func);

    
    // Visitar sub arvore da direite
    rec_post_order_traversal(root->right_node, v_func);
    
    // Visitar nó
    v_func(root->key);
}

void it_pre_order_traversal(Node* root, visit_func v_func) {

    if (root == NULL) return;

    Stack* s = stack_create();
    stack_push(s, root);

    while (!stack_is_empty(s)) {
        Node* n = (Node*) stack_pop(s); // Desempilha

        v_func(n->key); // Visita

        // empilha a direita primeiro, para que a esquerda saia antes
        if (n->right_node != NULL) {
            stack_push(s, n->right_node); // empilha
        }
        
        if (n->left_node != NULL) {
            stack_push(s, n->left_node); // empilha
        }
    }

    stack_destroy(&s);
}

void it_in_order_traversal(Node* root, visit_func v_func) {
    if (root == NULL || v_func ==  NULL) return;

    Stack* s = stack_create();
    Node* n = root;

    while (n != NULL || !stack_is_empty(s)) {
        // Cmainha para a esquerda, empilhando o caminho
        while (n != NULL) {
            stack_push(s, n);
            n = n->left_node;
        }

        // Chegou ao fim e agora desempilha
        n = (Node*) stack_pop(s);

        // Visitar a raiz
        v_func(n->key);

        // Agora vai para a direita
        n = n->right_node;
    }

    stack_destroy(&s);
}

void it_post_order_traversal(Node* root, visit_func v_func) {
    if (root == NULL || v_func == NULL) return;

    Stack *s = stack_create();
    Node* last_visited = NULL; // Ultimo nó visitado
    Node* n = root; // Nó atual que desce pela árvore

    while (!stack_is_empty(s) || n != NULL) {
        if (n != NULL) {
            // Empilha o caminho para a esquerda
            stack_push(s, n);
            n = n->left_node;
        } else {
            // Volta do null para esquerda
            // Pega o nó no topo da pilha
            Node* n_top = (Node*) stack_top(s);

            // Verifica se podemos ir para a sub-arvore da direita
            if (n_top->right_node != NULL && last_visited != n_top->right_node) {
                // Se o filha da direita existe e
                // se ainda não o visitamos
                n = n_top->right_node;
            } else {
                // Visita o nó do topo
                v_func(n_top->key);

                // Marca como visitado e remove da pilha
                last_visited = (Node*) stack_pop(s);

                // Mantem atual como null para que o loop
                // continua a desempilhar na proxima iteração
            }
        }
    }

    stack_destroy(&s);
}

void it_level_order_traversal(Node* root, visit_func v_func) {
    // verifica parametros
    if (root && v_func) {
        // cria a fila
        Queue* q = queue_create();

        // enfileirar a raiz
        enqueue(q, root);

        printf("chave raiz: %d\n", root->key);
        
        // iniciar o loop para percorrer os níveis da árvore
        while (!queue_is_empty(q)) {
            // desenfileira um no
            Node* n = (Node*) dequeue(q);
            printf("chave atual: %d\n", n->key);

            // visita o nó atual
            v_func(n->key);
            
            // enfileira os filhos da esquerda, depois da direita
            if (n->left_node != NULL) {
                enqueue(q, n->left_node);
            }
            
            if (n->right_node != NULL) {
                enqueue(q, n->right_node);
            }
        }

        queue_destroy(&q);
    }
}
