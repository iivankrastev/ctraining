#include <stdio.h>
#include <stdlib.h>

#include "graph_object/graph_object.h"

int main (void) {

    g_node *root;
    g_node curr;

    *root = init_node (root, 0, 3);
    /*
    g.root->left = init_node (g.root, 1, 2);
    g.root->right = init_node (g.root, 1, 4);

    (root->left).left = init_node (2, 1);
    (root->left).right = init_node (2, 2);

    (root->right).left = init_node (2, 3);
    (root->right).right = init_node (2, 5);
    */

    return 0;
}
