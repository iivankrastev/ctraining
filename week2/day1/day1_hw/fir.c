#include "fir.h"
#include <stdlib.h>
#include <stdio.h>

#define FIR32 32
#define FIR16 16

short int coefs [FIR32] = 
    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 1,
     1, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0};

short int coefs16 [FIR16] =
    {0,0,0,0,0,0,1,1,
     0,0,0,0,0,0,0,0};

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
    
    static unsigned int j = (FIR32 - 1);
    static int sum = 0; 
    int i;
    
    if (r->idx != 0)
	i = (r->idx - 1);
    else
	i = FIR32 - 1;

    sum += (int)coefs[j] * (int)r->buf[i];

    fprintf(stdout,"idx : %d coef: %d\t coef value : %hd\t sum : %d\n"
			    , i
			    , j
			    , coefs[j]
			    , sum);

    if (!j){ 
	j = (FIR32 -1);
	sum = 0;
    } else 
	j--;

    return;
}

void filter16 (ringbuf *r){
    
    static unsigned int j = (FIR16 - 1);
    static int sum = 0; 
    int i;
    
    if (r->idx != 0)
	i = (r->idx - 1);
    else
	i = FIR16 - 1;

    sum += (int)coefs16[j] * (int)r->buf[i];

    fprintf(stdout,"idx : %d coef: %d\t coef value : %hd\t sum : %d\n"
			    , i
			    , j
			    , coefs16[j]
			    , sum);

    if (!j){ 
	j = (FIR16 -1);
	sum = 0;
    } else 
	j--;

    return;
}

void print_coefs(){
    
    int i = 0;
    for (i; i < FIR32; i++)
	printf ("Index: %d Value: %hd\n", i, coefs[i]);
    return;
}


