#ifndef _GRAPH_
#define _GRAPH_

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

struct list {
	g_node v;
	struct list *n;
};
typedef struct list list;

struct queue {
	list *B, *E;
};
typedef struct queue queue;

void *queue_create(void);
void queue_destroy(void *);
int queue_put(void *, g_node);
int queue_get(void *, g_node *);
int queue_empty (void *); 
g_node init_node (int, int);
g_node get_beginning (void *);
void bft (void *, g_node);

#endif
