#ifndef _GRAPH_OBJECT_
#define _GRAPH_OBJECT_

#include <stdlib.h>

#include "../internal/graph.h"
#include "graph_object.h"

int queue_put(void *_ctx, g_node _v) {
	queue *ctx = (queue *)_ctx;
	list *l = (list *)malloc(sizeof (list));
	
	if (!l) return 0;
	
	l->v = _v;
	l->n = NULL;

	if (ctx->E) {
		ctx->E->n = l;
		ctx->E = l;
	} else {
		ctx->B = ctx->E = l;
	}
	
	return 1;
}

int queue_get(void *_ctx, g_node *v) {
	queue *ctx = (queue *)_ctx;
	list *l;
	
	if (!ctx->B) return 0;
	
	l = ctx->B;
	ctx->B = ctx->B->n;
	if (!ctx->B) ctx->E = NULL;
	
	*v = l->v;
	
	free(l);
	
	return 1;
}

void *queue_create(void) {
	queue *t = (queue *)malloc(sizeof (queue));
	
	if (!t) return NULL;
	
	t->B = NULL;
	t->E = NULL;
	
	return (void *)t;
}

void queue_destroy(void *_ctx) {
	queue *ctx = (queue *)_ctx;
	g_node v;
	
	while (queue_get(_ctx, &v));

	free(_ctx);

	return;
}

int queue_empty (void *_ctx) {

    queue *ctx = (queue *)_ctx;

    if (!ctx->B)    return 1;
    else	    return 0;
}


g_node init_node (g_node *root, int h, int w) {
    
    root = (g_node *)malloc(sizeof(g_node));
    g_node n;
    
    n.p.h = h;
    n.p.w = w;
    n.left = NULL;
    n.right = NULL;
    
    return n;
}

g_node get_beginning (void *_ctx){
    queue *ctx = (queue *)_ctx;
    return ctx->B->v;
}

#endif
