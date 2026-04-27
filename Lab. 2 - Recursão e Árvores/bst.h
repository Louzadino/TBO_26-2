#ifndef BST_H
#define BST_H

typedef struct Node Node;

typedef struct BST BST;

// Operações para estrutura node

// O valor do nó é a própria chave
Node* create_node(int key);

void print_node(Node* n);

void destroy_node(Node* n);

// Operações para estrutura bst

BST* create_bst();

void insert_bst(BST* bst, Node* node_z);

void destroy_bst(BST* bst);

#endif