#ifndef _FIR_
#define _FIR_

struct ringbuffer{
    int n, idx;
    short int *buf;
};

typedef struct ringbuffer ringbuf;

int init (ringbuf *ring, int N);
void push (ringbuf *r, short int d);
void filter32 (ringbuf *r);
void filter16 (ringbuf *r);
void print_coefs();
#endif 
