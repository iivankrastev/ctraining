#include "fir.h"
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

void filter32 (ringbuf *r){
    
    static int j = 32;
    int sum = 0;
    
    short int coefs [32] = 
    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 1,
     1, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0};
	
    sum += (int)coefs[j] * (int)r->buf[r->idx];
    (j == 0) ? j = 32 : j--;

    fprintf(stdout,"Element idx : %d coef: %d res : %d\n"
			    , r->idx
			    , j
			    , sum);

    return;
    
}


