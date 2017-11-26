#include <stdlib.h>
#include <stdio.h>

#include "internal/queue.h"
#include "queue_object.h"

void *queue_create(void) {
	queue *t = (queue *)malloc(sizeof (queue));
	
	if (!t) return NULL;
	
	t->B = NULL;
	t->E = NULL;
	
	return (void *)t;
}

void queue_destroy(void *_ctx) {
	queue *ctx = (queue *)_ctx;
	queue_datum t;
	
	while (queue_get(_ctx, &t));

	free(_ctx);

	return;
}

int queue_put(void *_ctx, queue_datum d) {
	queue *ctx = (queue *)_ctx;
	list *l = (list *)malloc(sizeof (list));
	
	if (!l) return 0;

	l->d = d;
	l->n = NULL;

	if (ctx->E) {
		ctx->E->n = l;
		ctx->E = l;
	} else {
		ctx->B = ctx->E = l;
	}
	
	return 1;
}

int queue_get(void *_ctx, queue_datum *d) {
	queue *ctx = (queue *)_ctx;
	list *l;
	
	if (!ctx->B) return 0;
	
	l = ctx->B;
	ctx->B = ctx->B->n;
	if (!ctx->B) ctx->E = NULL;
	
	*d = l->d;
	
	free(l);
	
	return 1;
}

int queue_search (void *_ctx,
		  queue_datum_type dtype,
		  queue_datum *d){
    
    while (queue_get(_ctx, d)){

	if (d->type == dtype){
	    printf("Type found\n");
	    return 1; 
	}
    }
    
    printf("type not found\n");
    return 0;
}

