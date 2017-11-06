#include "ringbuffer.h"
#include <stdlib.h>
#include <stdio.h>

int init (ringbuf *ring, int N){

    ring->buf = (short int *)calloc(N, sizeof(short int));
    if (!ring->buf)
	return 0;
    ring->idx = 0;
    ring->n = N;

    return 1;
}

void push (ringbuf *r, short int d){

    r->buf[r->idx] = d;
    r->idx = (r->idx + 1) % (r->n);
    
    return;
}

void print (ringbuf *r){
    
    int i;
    for (i = 0; i < r->n; i++)
	printf ("%hd%c", r->buf[i], (i == (r->n)) ? '\n' : ' ');
    
    return;
}


