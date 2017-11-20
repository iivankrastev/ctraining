#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main (void) {

    g_node *root;
    g_node curr;
    void *queue;
    
    root = (g_node *)malloc(sizeof(g_node));
    *root = init_node (0, 3);
    
    root->left = (g_node *)malloc(sizeof(g_node));
    *root->left = init_node (1, 2);

    root->right = (g_node *)malloc(sizeof(g_node));
    *root->right = init_node (1, 4);

    
    (*root->left).left = (g_node *)malloc(sizeof(g_node));
    *(*root->left).left = init_node (2, 1);

    (*root->left).right = (g_node *)malloc(sizeof(g_node));
    *(*root->left).right = init_node (2, 2);

    (*root->right).left = (g_node *)malloc(sizeof(g_node));
    *(*root->right).left = init_node (2, 3);

    (*root->right).right = (g_node *)malloc(sizeof(g_node));
    *(*root->right).right = init_node (2, 5);
    
    queue = queue_create();

    (void)queue_put(queue, *root);
    
    printf("**********BFT********\n");
    
    bft(queue, curr);

    return 0;
}

void bft (void *_ctx, g_node n);
