#ifndef _GRAPH_
#define _GRAPH_

#include "../graph_object.h"

struct list {
	g_node v;
	struct list *n;
};
typedef struct list list;

struct queue {
	list *B, *E;
};
typedef struct queue queue;

#endif
