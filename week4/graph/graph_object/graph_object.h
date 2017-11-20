#ifndef _GRAPH_OBJECT_
#define _GRAPH_OBJECT_

struct point {
   int h;
   int w;
};
typedef struct point point;

struct g_node {
   point p;
   struct g_node *left;
   struct g_node *right;
};
typedef struct g_node g_node;

void *queue_create(void);
void queue_destroy(void *);
int queue_put(void *, g_node);
int queue_get(void *, g_node *);
int queue_empty (void); 
g_node init_node (g_node *, int, int);
g_node get_beginning (void *);

#endif
